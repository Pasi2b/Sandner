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

class Depositer{
    private:
        Account& accd;
        int deposits;
    
    public:
        Depositer(Account& a, int d) : accd(a), deposits(d){};
        void operator()(){
            for(int i = 0; i < deposits; i++){
                accd.deposit(1);
            }
        };
};