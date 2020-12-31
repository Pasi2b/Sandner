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
    bool nodeadlock{false};
    bool livelock{false};
    
    CLI::App app("Dining phillosophers simulation");

    app.add_option("-n, --nodeadlock", nodeadlock, "Prevent a deadlock at all");

    app.add_option("-l, --livelock", livelock, "Simulate a livelock");
    CLI11_PARSE(app, argc, argv);

    /*
    mutex m_right;
    mutex m_left;

    Semaphore* sem = new Semaphore{3};

    
    */
    Semaphore* nodeadlock_pointer;

    if (nodeadlock){
        nodeadlock_pointer = new Semaphore();
    } else {
        nodeadlock_pointer = nullptr;
    }

    

    timed_mutex tm1;
    timed_mutex tm2;
    timed_mutex tm3;
    timed_mutex tm4;
    timed_mutex tm5;
    

    Philosopher p1(1, ref(tm1), ref(tm5));
    Philosopher p2(2, ref(tm2), ref(tm1));
    Philosopher p3(3, ref(tm3), ref(tm2));
    Philosopher p4(4, ref(tm4), ref(tm3));
    Philosopher p5(5, ref(tm5), ref(tm4));

    thread t1{p1, nodeadlock_pointer, livelock};
    thread t2{p2, nodeadlock_pointer, livelock};
    thread t3{p3, nodeadlock_pointer, livelock};
    thread t4{p4, nodeadlock_pointer, livelock};
    thread t5{p5, nodeadlock_pointer, livelock};

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
}