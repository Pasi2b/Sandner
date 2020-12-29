/*
    author: Sandner
*/

#include <iostream>
#include <mutex>
#include <queue>

#pragma once

class WorkQueue{

    private:
        std::mutex mtx;
        std::queue<WorkPacket> WorkPackets{};


    public:
        WorkQueue();
        WorkPacket pop();
        void push(WorkPacket WorkPacket);
};
