/*
    author: Sandner Pascal
*/  


#include <iostream>
#include <vector>
#include <thread>
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


int main(int argc, char const *argv[]){
    vector<string> inputs;

    CLI::App app("Factor numbers");
    app.add_option("number", inputs, "numbers to factor")
        ->required()
        ->check(checkValidator);
    bool asy{false};
    app.add_flag("-a, --async", asy, "async");
    CLI11_PARSE(app, argc, argv);
    
    try{
            app.parse(argc, argv);
            vector<InfInt> newinput;
            for(size_t i = 0; i < inputs.size(); i++){
                InfInt input_item = inputs[i];
                newinput.push_back(input_item);
                //cout << input_item << "\n" << flush;
            }
            for(size_t i = 0; i < newinput.size(); i++){
                vector<InfInt> factors = get_factors(newinput[i]);
                cout << newinput[i] << ": " << flush;
                for(size_t j = 0; j < factors.size(); j++){
                    cout << factors[j] << " " << flush;
                }
                cout << "\n" << flush;
            }
    }catch (const CLI::ParseError &error){
        return app.exit(error);
    }
}