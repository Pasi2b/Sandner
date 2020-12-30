/*
    author: Pascal Sandner
*/
#include <iostream>
#include "include/work_packet.h"
#include "include/work_queue.h"
#include <thread>
#include <mutex>
#include <queue>
#include <random>

using namespace std;


void worker (int id, WorkQueue& q){
    string output;
    double wait_worker;
    random_device rd;
    mt19937 gen{rd()};
    uniform_real_distribution<> dis{1, 10};

    while(true){   
        output =  "W" + to_string(id) + ": Want work packet \n";
        cout << output << flush;
        WorkPacket WP{q.pop()};
        wait_worker = dis(gen);
        chrono::milliseconds time_to_wait_worker{int (wait_worker * 1000)};
        output =  "W" + to_string(id) + ": Got work packet " + to_string(WP.get_id()) + "\n";
        cout << output << flush;
        this_thread::sleep_for(time_to_wait_worker);
        output = "W" + to_string(id) + ": Processed work packet " + to_string(WP.get_id()) + " (" + to_string(wait_worker) + ")" + "\n";
        cout << output << flush;
    }
}



int main() {
    int i{0};
    WorkQueue q(10);


    thread t1{worker, 1, ref(q)};
    thread t2{worker, 2, ref(q)};
    thread t3{worker, 3, ref(q)};

    double wait_boss;
    random_device rd;
    mt19937 gen{rd()};
    uniform_real_distribution<> dis{0, 1};


    while(true){
        WorkPacket WP{WorkPacket(i)};
        q.push(WP);
        wait_boss = dis(gen);
        chrono::milliseconds time_to_wait_boss{int (wait_boss * 1000)};
        cout << "B: Submitted work packet " << i << endl;
        this_thread::sleep_for(time_to_wait_boss);
        i++;
    }

    t1.join();
    t2.join();
    t3.join();
}