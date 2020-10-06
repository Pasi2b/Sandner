/*
    author: Pascal Sandner
    date:   05.10.2020
    desc:   02_threads
*/

#include <iostream>
#include <thread>
#include <random>

using namespace std;
using namespace std::literals;



class Car{
    private: 
        string autotyp;
        
    public:
        void operator()(){
            random_device rd;
            mt19937 gen{rd()};
            uniform_real_distribution<> dis{1, 10};
            int runden = 0;

            while(true){
                runden++;
            cout << to_string(runden) << " " << autotyp << " " << dis(gen) << "\n" << flush;
                this_thread::sleep_for(1s);   
            }
        }
    Car(string Autotyp){
      this->autotyp = Autotyp;
    }
};


void rennen(){
    int runden2 = 0;
    string autotyp2 = "Toyota GT86";
    random_device rd;
    mt19937 gen{rd()};
    uniform_real_distribution<> dis{1, 10};

    while(true){
        runden2++;
        cout << to_string(runden2) << " " << autotyp2 << " " << dis(gen) << "\n" << flush;
        this_thread::sleep_for(1s);   
    }
}
     


int main(){
    Car toyota("Toyota GT86") ;   
    thread t1{ref(toyota)};
    thread t2{rennen};
    t1.join();
    t2.join();
}