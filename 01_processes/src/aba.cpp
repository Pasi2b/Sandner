/*
    author: Pascal Sandner
    date:   28.09.2020
    desc: 01_processes
*/
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <csignal>
#include <cstdlib>

using namespace std;


int main() {
    auto pid{fork()};
    int count = 1;
    while(true){              
        if(pid > 0) {
            cout << "B" << flush;
            chrono::milliseconds sleeptime(500);
            this_thread::sleep_for(sleeptime);
            if(count == 6){
                kill(pid, SIGKILL);
                quick_exit(EXIT_SUCCESS);
            }
        }else if(pid == 0){
            cout << "A" << flush;
            chrono::milliseconds sleeptime(500);
            this_thread::sleep_for(sleeptime);         
        }
        count ++;
    }
}
