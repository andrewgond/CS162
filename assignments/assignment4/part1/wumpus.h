#ifndef WUMPUS_H
#define WUMPUS_H 

//Wumpus Interface
#include "event.h"
#include <iostream>
#include <string>

class Wumpus : public Event {
    private:

    public:
        Wumpus();
        ~Wumpus();
        int interact(bool);
        void print_precept();


    
};

#endif