/*
    author: Pascal Sandner
*/
#include <iostream>
#include "include/work_packet.h"
#include "include/work_queue.h"
#include <thread>
#include <mutex>
#include <queue>

using namespace std;

/*
void worker (int id, WorkQueue& q){
    while(true){
       
        cout << "W" << id << ": Want work packet" << endl;
        cout << "W" << id << ": Got work packet " << WorkPacket.get_id() << endl;
        this_thread::sleep_for(1s);
        cout << "W" << id << ": Processed work packet " << WorkPacket.get_id() << endl;
    
    }
}
*/


int main() {
    int i{0};

    while(true){
        WorkPacket WorkPacket(i);
        cout << "B: Submitted work packet " << i << endl;
        this_thread::sleep_for(0.5s);
        i++;
    }
}