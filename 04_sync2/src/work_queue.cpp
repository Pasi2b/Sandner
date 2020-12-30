/*
    author: Pascal Sandner
*/
#include <iostream>
#include "include/work_packet.h"
#include "include/work_queue.h"
#include <thread>
#include <mutex>

using namespace std;


void WorkQueue::push(WorkPacket wp) {
  unique_lock<mutex> lck{mtx};
  not_full.wait(lck, [this]{return WQ.size() < size;});
  WQ.push(wp);
  not_empty.notify_one();
}

WorkPacket WorkQueue::pop() {
  unique_lock<mutex> lck{mtx};
  not_empty.wait(lck, [this]{return WQ.size();});
  WorkPacket wp = WQ.front();
  WQ.pop();
  not_full.notify_one();
  return wp;
}

