/*
    author: Sandner Pascal
*/
#pragma once

#include "timeutils.h"
#include <chrono>

class Clock{
    private:
        std::string name;
        std::chrono::time_point<std::chrono::system_clock> curr_time = std::chrono::system_clock::now();

    public:
        Clock(std::string name_): name{name_}{};

    
        Clock(std::string name_, int hours_, int minutes_, int seconds_){
            name = name_;
            curr_time =  clock_functions::set_time(curr_time, hours_, minutes_, seconds_);       
        };
        
        
        void set_time(int hours, int minutes, int seconds);
        std::tuple<int, int, int> get_time();

        void operator()();
};
