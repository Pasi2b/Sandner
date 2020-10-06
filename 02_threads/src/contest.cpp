/*
    author: Pascal Sandner
    date:   05.10.2020
    desc:   02_threads
*/

#include <iostream>
#include <thread>

using namespace std;


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
        


int main(/*int argc, char *argv[]*/){    
    thread t{rennen};
    t.join();
}