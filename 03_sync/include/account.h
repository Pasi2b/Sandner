/*
    author: Pascal Sandner 
    date:   14.10.2020
    desc:   Übung3 - Sync
*/

#include <iostream>
#include <mutex>

class Account{
        private:
            int balance{0};
            std::mutex mtx;
            
        public:
            Account(int amount) : balance{amount}{};
            int get_balance();  
            void deposit(int amount);
            bool withdraw(int amount);
    };