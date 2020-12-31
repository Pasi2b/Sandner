/*
    author: Pascal Sandner
*/

#pragma once

#include <mutex>
#include <atomic>
#include <condition_variable>

class Semaphore{
    private:
        const int MAXIMUM = 4; 
        std::atomic<int> counter;
        std::mutex mtx;
        std::condition_variable not_empty;
        std::condition_variable not_full;
    public:
        Semaphore();
        Semaphore(int start_value);
        void acquire();
        void release();
        int available_permits();
};