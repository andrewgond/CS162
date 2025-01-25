#ifndef STALACTITES_H
#define STALACTITES_H 

//Stalactites Interface
#include "event.h"
#include <iostream>
#include <string>

class Stalactites : public Event {
    private:

    public:
        Stalactites();
        ~Stalactites();
        int interact(bool);
        void print_precept();


    
};

#endif
