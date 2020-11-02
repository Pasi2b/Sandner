/*
    author: Pascal Sandner 
    date:   14.10.2020
    desc:   Übung3 - Sync
*/

#include <iostream>
#include "include/account.h"
#include <thread>

using namespace std;

int main(){
    /* Punkt1
    Account acc{15};
    cout << acc.get_balance();
    cout << "\n";
    acc.withdraw(6);
    cout << acc.get_balance();
    cout << "\n";
    acc.withdraw(10);
    cout << acc.get_balance();
    cout << "\n";
    */

    Account acc2{1};
    cout << acc2.get_balance();
    cout << "\n";
    thread t1([ref(acc2.withdraw(1))](){});
    thread t2([ref(acc2.withdraw(1))](){});
    t1.join();
    t2.join();
    cout << "\n";
    cout << acc2.get_balance();
}