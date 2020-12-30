/*
    author: Sandner Pascal
*/

#include "philosopher.h"
#include "semaphore.h"
#include "CLI11.hpp"
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

int main(int argc, char* const argv[]){
    
    CLI::App app("Dining phillosophers simulation");

    bool nodeadlock;
    app.add_option("-n, --nodeadlock", nodeadlock, "Prevent a deadlock at all");

    bool livelock;
    app.add_option("-l, --livelock", livelock, "Simulate a livelock");
    CLI11_PARSE(app, argc, argv);

    /*
    mutex m_right;
    mutex m_left;

    Semaphore* sem = new Semaphore{3};

    
    */

    bool nodeadlock{false};
    bool livelock{false};

    if(nodeadlock){
        nodeadlock = true;
    }

    if(livelock){
        livelock = true;
    }

    Semaphore* sem = nodeadlock ? new Semaphore(3) : nullptr;

    timed_mutex tm1;
    timed_mutex tm2;
    timed_mutex tm3;

    Philosopher p1(1, tm1, tm2);
    Philosopher p2(2, tm2, tm3);
    Philosopher p3(3, tm3, tm1);

    thread t1{p1, sem, livelock};
    thread t2{p2, sem, livelock};
    thread t3{p3, sem, livelock};

    t1.join();
    t2.join();
    t3.join();
}