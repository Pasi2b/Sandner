/*
    author: Pascal Sandner
*/
#include <iostream>
#include "include/work_packet.h"
#include "include/work_queue.h"
#include <thread>

using namespace std;

int main() {
    int i{1};

    while(true){
        WorkPacket WorkPacket(i);
        cout << "B: Submitted work packet " << i << endl;
        this_thread::sleep_for(0.5s);
        i++;
    }
}