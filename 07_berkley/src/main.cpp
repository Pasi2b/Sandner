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

class TimeSlave{
    private:
        string name;
        Clock clock;
        Channel channel;

    public:
        TimeSlave(string name_, int hours_, int minutes_, int seconds_): clock(name_ + " clock ", hours_, minutes_, seconds_){
            name = name_;
        }

        void operator()(){
            clock();
        }

        Channel* get_channel(){
            return &channel;
        }
};

class TimeMaster{
    private:
        string name;
        Clock clock;
        Channel* channel1;
        Channel* channel2;

    public:
        TimeMaster(string name_, int hours_, int minutes_, int seconds_): clock(name_ + " clock ", hours_, minutes_, seconds_){
            name = name_;
        }

        void operator()(){
            clock();
        }

        void set_Channel1(Channel* channel){
            channel1 = channel;
        }

        void set_Channel2(Channel* channel){
            channel2 = channel;
        }
};




int main(){

    //thread t1(Clock{"testclock"});
    //thread t2(Clock{"testclock", 12, 00, 00});
    //t1.join();
    //t2.join();

    TimeSlave slave1(TimeSlave{"testslave", 12, 00, 00});
    TimeSlave slave2(TimeSlave{"testslave2", 11, 00, 00});
    TimeMaster timemaster1(TimeMaster{"testmaster", 10, 00, 00});

    thread s1{ref(slave1)};
    thread s2{ref(slave2)};
    thread m1{ref(timemaster1)};

    s1.join();
    s2.join();
    m1.join();
}