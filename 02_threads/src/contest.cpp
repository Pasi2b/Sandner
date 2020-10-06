/*
    author: Pascal Sandner
    date:   05.10.2020
    desc:   02_threads
*/

#include <iostream>
#include <thread>
#include <random>
#include <iomanip>
#include <sstream>

using namespace std;
using namespace std::literals;
using namespace chrono;



class Car{
    private: 
        string autotyp;
        
    public:
        void operator()(){
            random_device rd;
            mt19937 gen{rd()};
            uniform_real_distribution<> dis{1, 10};
            int runden = 0;
            double time{};
            ostringstream buf;

            while(true){
                time = dis(gen);
                runden++;
                buf << to_string(runden) << " " << autotyp << ": " << setprecision(3) << dis(gen) << "\n" << flush;
                cout << buf.str();
                buf.str("");
                this_thread::sleep_for(milliseconds(static_cast<int>(time * 1000)));   
            }
        }
    Car(string Autotyp){
      this->autotyp = Autotyp;
    }
};


void rennen(){
    int runden2 = 0;
    string autotyp2 = "Toyota Supra";
    random_device rd;
    mt19937 gen{rd()};
    uniform_real_distribution<> dis{1, 10};
    double time{};
    ostringstream buf2;
    

    while(true){
        time = dis(gen);
        runden2++;
        buf2 << to_string(runden2) << " " << autotyp2 << ": " << setprecision(3) << dis(gen) << "\n" << flush;
        cout << buf2.str();
        buf2.str("");
        this_thread::sleep_for(milliseconds(static_cast<int>(time * 1000)));   
    }
}
     


int main(){
    Car toyota("Toyota GT86") ;   
    thread t1{ref(toyota)};
    thread t2{rennen};
    t1.join();
    t2.join();
}