/*
    author: Sandner Pascal
*/

#include <iostream>
#include <chrono>
#include <thread>
#include "timeutils.h"
#include "clock.h"

using namespace std;

void Clock::operator()(){
    while(true){
        cout << name << ": " << curr_time << endl;
        this_thread::sleep_for(1s);
        curr_time += 1s;
    }
}
