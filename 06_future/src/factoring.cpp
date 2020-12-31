/*
    author: Sandner Pascal
*/  


#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <chrono>
#include "CLI11.hpp"
#include "calc_factors.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#pragma GCC diagnostic ignored "-Wsign-compare"
#include "InfInt.h"
#pragma GCC diagnostic pop




using namespace std;


string checkValidator(const string& s){
    std::size_t found = s.find_first_not_of("0123456789");
    if (found != string::npos){
         throw CLI::ValidationError(s + " contains not numeric character");
    }else{
        return ""; 
    }
}

void print(vector<InfInt> &numbers, vector<shared_future<vector<InfInt>>> &result){
    for(size_t i = 0; i < result.size(); i++){    
        cout << numbers[i] << ": "<< flush;
        vector<InfInt> results = result[i].get();
        for(size_t j = 0; j < results.size(); j++){
            cout << results[j] <<" "<< flush;
        }
        cout << "\n" << flush;
    }
}


void checkFactors(vector<InfInt> &numbers, vector<shared_future<vector<InfInt>>> &results){
    for(size_t i = 0; i < numbers.size(); i++){
        vector<InfInt> result = results[i].get();
        InfInt number{result[0]*result[1]};
        for(size_t j = 2; j < result.size(); j++){
            number = number*result[j];       
        }
        if(number != numbers[i]){
            cerr << numbers[i] << "primefactors are incorrect" << number << "\n"<<flush;
        }
    }
}


int main(int argc, char const *argv[]){
    vector<string> inputs;

    CLI::App app("Factor numbers");
    app.add_option("number", inputs, "numbers to factor")
        ->required()
        ->check(checkValidator);
    bool async_option{false};
    app.add_flag("-a, --async", async_option, "async");
    CLI11_PARSE(app, argc, argv);
    
    try{
            app.parse(argc, argv);
            vector<InfInt> newinput;
            vector<shared_future<vector<InfInt>>> result;

            for(size_t i = 0; i < inputs.size(); i++){
                InfInt input_item = inputs[i];
                newinput.push_back(input_item);
            }

            if(async_option == false){
                for(size_t i = 0; i < newinput.size(); i++){
                /*vector<InfInt> factors = get_factors(newinput[i]);
                cout << newinput[i] << ": " << flush;
                for(size_t j = 0; j < factors.size(); j++){
                    cout << factors[j] << " " << flush;
                }
                cout << "\n" << flush;*/
                    result.push_back(async(launch::deferred, get_factors, newinput[i]));
                }
                auto start = chrono::system_clock::now();
                for(size_t i = 0; i < result.size(); i++){
                    result[i].wait();
                }
                auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start);
                thread t1([&](){print(newinput, result);});
                thread t2([&](){checkFactors(newinput, result);});
                t1.join();
                t2.join();
                cout << "Time elapsed used for factoring: " << duration.count() << "ms" << "\n";
                
            }else if(async_option == true){
                for(size_t i = 0; i < newinput.size(); i++){
                    result.push_back(async(launch::async, get_factors, newinput[i]));
                }
                auto start = chrono::system_clock::now();
                for(size_t i = 0; i < result.size(); i++){
                    result[i].wait();
                }
                auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start);
                thread t1([&](){print(newinput, result);});
                thread t2([&](){checkFactors(newinput, result);});
                t1.join();
                t2.join();
                cout << "Time elapsed used for factoring: " << duration.count() << "ms" << "\n";
                
            }
            /*
            for(size_t i = 0; i < result.size(); i++){
                cout << newinput[i] << ": " << flush;
                vector<InfInt> results = result[i].get();
                for(size_t j = 0; j < result.size(); j++){
                    cout << results[j] << " " << flush;
                }
                cout << "\n" << flush;
            }
            */
        }catch (const CLI::ParseError &error){
            return app.exit(error);
        }
}