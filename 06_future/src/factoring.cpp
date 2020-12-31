/*
    author: Sandner Pascal
*/  


#include <iostream>
#include <vector>
#include <thread>
#include "CLI11.hpp"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#pragma GCC diagnostic ignored "-Wsign-compare"
#include "InfInt.h"
#pragma GCC diagnostic pop



using namespace std;


string checkValidator(const string& s){
    std::size_t found = s.find_first_not_of("0123456789");
    if (found != string::npos){
         throw CLI::ValidationError(s +" contains not numeric character");
    }else{
        return ""; 
    }
}



int main(int argc, char const *argv[]){
    vector<string> inputs;

    CLI::App app("Factor numbers");
    app.add_option("number", inputs, "numbers to factor")
        ->check(checkValidator);
    bool asy{false};
    app.add_flag("-a, --async", asy, "async");
    CLI11_PARSE(app, argc, argv);
    
}