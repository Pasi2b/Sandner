/*
    author: Pascal Sandner 
    date:   14.10.2020
    desc:   Übung3 - Sync
*/

#include <iostream>
#include "include/account.h"

using namespace std;

int main(){
    Account acc{15};
    cout << acc.get_balance();
    cout << "\n";
    acc.withdraw(6);
    cout << acc.get_balance();
    cout << "\n";
    acc.withdraw(10);
    cout << acc.get_balance();
    cout << "\n";
}