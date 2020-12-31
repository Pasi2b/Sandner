/*
    author: Sandner Pascal
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <sstream>
#include "philosopher.h"
#include "semaphore.h"

using namespace std;


recursive_mutex out_mtx;

void println() {
    lock_guard<recursive_mutex> lg{out_mtx};
    cout << endl;
}

template<typename T, typename... Rest>
void println(const T& word, const Rest&... rest) {
    lock_guard<recursive_mutex> lg{out_mtx};
    cout << word << ' ';
    println(rest...);
}



void Philosopher::operator()(Semaphore* sem, bool livelock) {
    while (true){
        println("Philosopher", id, "is thinking...");
        this_thread::sleep_for(1s);

        println("Philosopher", id, "attempts to get left fork");
        if(sem != nullptr){
            sem->acquire();
        }
        left_fork.lock();
        println("Philosopher", id, "got left fork. Now he wants the right one...");

        this_thread::sleep_for(5s);

        println("Philosopher", id, "attempts to get right fork");
        if (livelock){
            while(!right_fork.try_lock_for(chrono::seconds(3))) {
                this_thread::sleep_for(100ms);

                if (sem != nullptr) {
                    sem->release();
                }

                left_fork.unlock();
                println("Philosopher", id, "released left fork due to timeout getting the right one!");
            }
            this_thread::sleep_for(3s);
            continue;
        } else {
            right_fork.lock();
        }

        println("Philosopher", id, "got right fork. Now he is eating...");
        this_thread::sleep_for(2s);
        println("Philosopher", id, "finished eating");

        if(sem != nullptr){
            sem->release();
        }
        left_fork.unlock();
        println("Philosopher", id, "released left fork");
        println("currently", sem->available_permits(), "left forks available");
        right_fork.unlock();
        println("Philosopher", id, "released right fork");
    }
}


