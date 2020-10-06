/*
    author: Pascal Sandner
    date:   05.10.2020
    desc:   02_threads
*/

#include <iostream>
#include <thread>

using namespace std;
using namespace std::literals;



class Car{
    private: 
        string autotyp;
    public:
        void operator()(){
            int runden = 0;

            while(true){
                runden++;
            cout << to_string(runden) << " " << autotyp << "\n" << flush;
                this_thread::sleep_for(1s);   
            }
        }
    Car(string Autotyp){
      this->autotyp = Autotyp;
    }
};

/*
void rennen(){
    int runden = 0;
    string autotyp = "Toyota GT86";

    while(true){
        runden++;
        cout << runden << " " << autotyp << endl;
        cout << flush;
        this_thread::sleep_for(1s);   
    }
}
*/      


int main(){
    Car toyota("Toyota GT86") ;   
    thread t1{ref(toyota)};
    t1.join();
}