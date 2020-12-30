/*
    author: Sandner Pascal
*/

#include <thread>
#include <mutex>
#include <vector>

class Philosopher{
    private:
        int id;
        std::mutex& left_fork;
        std::mutex& right_fork;

    public:
        Philosopher(int id, std::mutex& left_f, std::mutex& right_f) :
            id(id), left_fork(left_f), right_fork(right_f) {};
        
        void operator()();
};