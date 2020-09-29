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
#include <cerrno>
#include <sys/wait.h>

using namespace std;


int main(int argc, char const* argv[]) {
    auto pid{fork()};
    int status{};
    int status2{};

    if(pid == 0){
        try{
            execl("charout", "charout", "A", nullptr);        
        }catch(...){
            cerr << "starting charout failed: No such file or directory" << errno << endl;
        }
    }else if(pid > 0) {
        auto pid2{fork()};
        if(pid2 == 0){
            try{
                execl("charout", "charout", "B", nullptr);        
            }catch(...){
                cerr << "starting charout failed: No such file or directory" << errno << endl;
            }
        }else if(pid2 > 0){
            cout << "waiting for 3 seconds" << endl;
            sleep(3);
            cout << "killing both subprocesses with pids " << pid << " and " << pid2 << endl;
            kill(pid, SIGKILL);  
            kill(pid2, SIGKILL);
            cout << "waiting for both subprocesses to be dead" << endl;
            waitpid(pid, &status, 0);
            waitpid(pid2, &status2, 0);
            cout << "subprocesses " << pid << " exited with " << status << endl;
            cout << "subprocesses " << pid2 << " exited with " << status2 << endl;
        }           
    }                      
}