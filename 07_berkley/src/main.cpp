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
    t1.join();
}