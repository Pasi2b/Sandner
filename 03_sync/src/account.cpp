/*
    author: Pascal Sandner 
    date:   14.10.2020
    desc:   Übung3 - Sync
*/

#include <iostream>
#include "include/account.h"
#include <mutex>
#include <thread>

using namespace std;

class Depositer{
    private:
        Account& accd;
    
    public:
        Depositer(Account& a) : accd(a){};
        void operator()(){
            for(int i = 0; i < 5; i++){
                accd.deposit(1);
            }
        };
};

void Account::deposit(int amount){
    unique_lock<mutex> lock{mtx};   
    balance += amount;
}

bool Account::withdraw(int amount){

    lock_guard<mutex> lock{mtx};
    this_thread::yield();
    if(amount <= get_balance()){     
        balance -= amount;
        cout << "Erfolgreiches Abheben" << endl;
        return true;
    }
    cout << "Abheben fehlgeschlagen" << endl;
    return false;
}

int Account::get_balance(){
    return balance;
}
