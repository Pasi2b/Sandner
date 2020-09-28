/*
    author: Pascal Sandner
    date:   28.09.2020
    desc: 01_processes
*/
#include <iostream>
#include <unistd.h>

using namespace std;


int main() {
    auto pid{fork()};
    while(true){        
        if(pid > 0) {
            cout << "B" << flush;
            sleep(0.5);
        }else if(pid == 0){
            cout << "A" << flush;
            sleep(0.5);
        }
    }
}
