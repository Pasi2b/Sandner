/*
    author: Pascal Sandner 
    date:   14.10.2020
    desc:   Übung3 - Sync
*/

#include <iostream>
#include "include/account.h"
#include <thread>
#include "include/CLI11.hpp"

using namespace std;

int main(int argc, char* const argv[]){
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


    // Nummer 7
    CLI::App app("Account app");
    int balance{0};

    app.add_option("balance", balance, "Initial balance")->required();
    int deposits{5};
    app.add_option("-d,--deposits", deposits, "Count of deposits", true);

    CLI11_PARSE(app, argc, argv);



    Account acc2{balance};
    Depositer depo{acc2, deposits};
    cout << acc2.get_balance();
    cout << "\n";
    thread t3(ref(depo));
    thread t4(ref(depo));
    t3.join();
    t4.join();
    //thread t1([ref(acc2.withdraw(1))](){});
    //thread t2([ref(acc2.withdraw(1))](){});
    //t1.join();
    //t2.join();
    cout << "\n";
    cout << acc2.get_balance();
    cout << "\n";
}