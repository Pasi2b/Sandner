/*
    author: Pascal Sandner
    date:   28.09.2020
    desc: 01_processes
*/
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>


using namespace std;


int main() {
    auto pid{fork()};
    while(true){        
        if(pid > 0) {
            cout << "B" << flush;
            chrono::milliseconds sleeptime(500);
            this_thread::sleep_for(sleeptime);
        }else if(pid == 0){
            cout << "A" << flush;
            chrono::milliseconds sleeptime(500);
            this_thread::sleep_for(sleeptime);
        }
    }
}
