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
    
    if(pid == 0){
        try{
            execl("charout", "charout", "A", nullptr);        
        }catch(...){
            cerr << "charout ist nicht verfügbar!" << errno << endl;
        }
    }else if(pid > 0) {
        auto pid2{fork()};
        if(pid2 == 0){
            try{
                execl("charout", "charout", "B", nullptr);        
            }catch(...){
                cerr << "charout ist nicht verfügbar!" << errno << endl;
            }
        }else if(pid2 > 0){
            sleep(3);
            kill(pid, SIGKILL);  
            kill(pid2, SIGKILL);
            waitpid(pid, &status, 0);
            waitpid(pid2, &status, 0);
        }           
    }                      
}