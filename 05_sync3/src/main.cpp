/*
    author: Sandner Pascal
*/

#include "philosopher.h"
#include "semaphore.h"
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

int main(){
    
    mutex m_right;
    mutex m_left;

    Semaphore* sem = new Semaphore{3};

    Philosopher p1(1, m_right, m_left);
    Philosopher p2(2, m_right, m_left);
    Philosopher p3(3, m_right, m_left);

    thread t1{p1, sem};
    thread t2{p2, sem};
    thread t3{p3, sem};

    t1.join();
    t2.join();
    t3.join();
}