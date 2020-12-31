/*
    author: Sandner Pascal 
*/

#include "semaphore.h"

#include <mutex>

using namespace std;

void Semaphore::release(){
    unique_lock<mutex> ul{mtx};
    not_empty.wait(ul, [this](){return (counter >= 0);});
    counter--;
    not_full.notify_one();
}

void Semaphore::acquire(){
    unique_lock<mutex> ul{mtx};
    not_full.wait(ul, [this](){return (counter < MAXIMUM);});
    counter++;
    not_empty.notify_one();
}

int Semaphore::available_permits(){
    return MAXIMUM - counter;
}

Semaphore::Semaphore(){
    counter.store(0);
}

Semaphore::Semaphore(int start_value){
    counter.store(start_value);
}