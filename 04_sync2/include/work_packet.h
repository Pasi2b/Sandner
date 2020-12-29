/*
    author: Sandner Pascal
*/

#include <iostream>
#pragma once

class WorkPacket{
    private:
        int id;

    public:
        WorkPacket(int id) : id(id){};
        int get_id() const{
            return id;
        }
};

