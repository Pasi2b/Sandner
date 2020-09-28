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

int main(int argc, char const* argv[]){

    if(argc == 2){
        while(true){
            cout << argv[1] << flush;
            chrono::milliseconds sleeptime(500);
            this_thread::sleep_for(sleeptime);
        }
    }
}