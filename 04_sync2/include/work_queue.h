/*
    author: Sandner
*/
#pragma once

#include <iostream>
#include <mutex>
#include <queue>
#include <condition_variable>
#include "work_packet.h"

class WorkQueue{

    private:
        std::queue <WorkPacket> WQ;
        std::mutex mtx;
        std::condition_variable not_empty;
        std::condition_variable not_full;
        std::size_t size;
        

    public:
        WorkQueue(size_t size_){
            size = size_;
            
        };
        WorkPacket pop();
        void push(WorkPacket wp);
};
