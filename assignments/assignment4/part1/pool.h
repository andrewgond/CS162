#ifndef POOL_H
#define POOL_H 

#include "event.h"
#include <iostream>
#include <string>

//Pool Interface
class Pool : public Event {
    private:

    public:
        Pool();
        ~Pool();
        int interact(bool);
        void print_precept();


    
};

#endif