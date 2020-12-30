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


void worker (int id, WorkQueue& q){
    string output;

    while(true){   
        output =  "W" + to_string(id) + ": Want work packet \n";
        cout << output << flush;
        WorkPacket WP{q.pop()};
        output =  "W" + to_string(id) + ": Got work packet " + to_string(WP.get_id()) + "\n";
        cout << output << flush;
        this_thread::sleep_for(1s);
        output + "W" + to_string(id) + ": Processed work packet " + to_string(WP.get_id()) + "\n";
        cout << output << flush;
    }
}



int main() {
    int i{0};
    WorkQueue q(10);


    thread t1{worker, 1, ref(q)};
    thread t2{worker, 2, ref(q)};

    while(true){
        WorkPacket WP{WorkPacket(i)};
        q.push(WP);
        cout << "B: Submitted work packet " << i << endl;
        this_thread::sleep_for(0.5s);
        i++;
    }

    t1.join();
    t2.join();
}