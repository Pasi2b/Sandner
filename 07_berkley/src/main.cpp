/*
    author: Sandner Pascal
*/

#include <iostream>
#include <thread>
#include <chrono>
#include "timeutils.h"
#include "clock.h"
#include "pipe.h"

using namespace std;



class TimeSlave{
    private:
        string name;
        Clock clock;

    public:
        TimeSlave(string name_, int hours_, int minutes_, int seconds_): clock(name_ + " clock", hours_, minutes_, seconds_){
            name = name_;
        }

        void operator()(){
            clock();
        }
};

class TimeMaster{
    private:
        string name;
        Clock clock;

    public:
        TimeMaster(string name_, int hours_, int minutes_, int seconds_): clock(name_ + " clock", hours_, minutes_, seconds_){
            name = name_;
        }

        void operator()(){
            clock();
        }
};

class Channel{
    private:
        Pipe<long> p1;
        Pipe<long> p2;

    public:
        Pipe<long>& get_pipe1(){
            return p1;
        }

        Pipe<long>& get_pipe2(){
            return p2;
        }
};


int main(){

    //thread t1(Clock{"testclock"});
    //thread t2(Clock{"testclock", 12, 00, 00});
    //t1.join();
    //t2.join();

    thread slave1(TimeSlave{"testslave", 12, 00, 00});
    thread slave2(TimeSlave{"testslave2", 11, 00, 00});
    thread timemaster1(TimeMaster{"testmaster", 10, 00, 00});
    slave1.join();
    slave2.join();
    timemaster1.join();
}