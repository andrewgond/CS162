#ifndef GOLD_H
#define GOLD_H 

#include "event.h"
#include <iostream>
#include <string>

//Gold Interface
class Gold : public Event {
    private:

    public:
        Gold();
        ~Gold();
        int interact(bool);
        void print_precept();


    
};

#endif