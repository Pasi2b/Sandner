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
        void operator()(double& totaltime){
            random_device rd;
            mt19937 gen{rd()};
            uniform_real_distribution<> dis{1, 10};
            int runden = 0;
            double time{};
            ostringstream buf;

            while(runden <= 9){
                time = dis(gen);
                totaltime += time;
                runden++;
                buf << to_string(runden) << " " << autotyp << ": " << setprecision(3) << dis(gen) << "s" << "\n" << flush;
                cout << buf.str();
                buf.str("");
                this_thread::sleep_for(milliseconds(static_cast<int>(time * 1000)));   
            }
        }

    string get_name(){
        return autotyp;
    }

    Car(string Autotyp){
      this->autotyp = Autotyp;
    }
};


void rennen(double& totaltime2){
    int runden2 = 0;
    string autotyp2 = "Toyota Supra";
    random_device rd;
    mt19937 gen{rd()};
    uniform_real_distribution<> dis{1, 10};
    double time{};
    ostringstream buf2;

    while(runden2 <= 9){
        time = dis(gen);
        totaltime2 += time;
        runden2++;
        buf2 << to_string(runden2) << " " << autotyp2 << ": " << setprecision(3) << dis(gen) << "s" << "\n" << flush;
        cout << buf2.str();
        buf2.str("");
        this_thread::sleep_for(milliseconds(static_cast<int>(time * 1000)));   
    }
}
     


int main(int argc, char* argv[]){    
    if(argc > 2){
        cout << ("Sie verwenden zu viele Zeilenargumente!") << endl;
    }else if(argc == 2){
        string arg{argv[1]};
        if(arg == "-h" or arg == "--help"){
           cout << "Usage: contest [-h | --help | LAPS]" << endl; 
        }else{
            cout << "Unerwarteter Fehler" << endl;
        }
    }else{
            double totaltime{0};
    double totaltime2{0};
    Car toyota("Toyota GT86") ;   
    thread t1{ref(toyota), ref(totaltime)};
    thread t2{rennen, ref(totaltime2)};
    t1.join();
    t2.join();
    
    if(totaltime < totaltime2){
        cout << endl << "Sieger ist: " << toyota.get_name() << " mit " << totaltime << "s" <<endl;
        cout << "Verliere ist: Toyota Supra mit " << totaltime2 << "s" << endl; 
    }else{   
        cout << endl << "Sieger ist: Toyota Supra mit " << totaltime2 << "s" << endl;
        cout << "Verliere ist: " << toyota.get_name() << " mit " << totaltime << "s" << endl; 
    }
    }

}