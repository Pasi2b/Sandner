/*
    author: Pascal Sandner 
    date:   14.10.2020
    desc:   Übung3 - Sync
*/

#include <iostream>
#include "include/account.h"

using namespace std;

void Account::deposit(int amount){
    balance += amount;
}

bool Account::withdraw(int amount){
    
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
