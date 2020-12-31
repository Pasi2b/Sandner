/*
    author: Sandner Pascal
*/

#include <iostream>
#include <thread>
#include <chrono>
#include "timeutils.h"
#include "clock.h"

using namespace std;






int main(){

    thread t1(Clock{"testclock"});
    thread t2(Clock{"testclock", 12, 00, 00});
    t1.join();
    t2.join();

    
}