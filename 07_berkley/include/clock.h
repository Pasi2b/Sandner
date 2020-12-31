/*
    author: Sandner Pascal
*/
#pragma once

#include "timeutils.h"
#include <chrono>

class Clock{
    private:
        std::string name;
        std::chrono::time_point<std::chrono::system_clock> curr_time;

    public:
        Clock(std::string name_){
            curr_time = std::chrono::system_clock::now();
            name = name_;
        };
        void operator()();
};
