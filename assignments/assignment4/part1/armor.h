#ifndef ARMOR_H
#define ARMOR_H 

//Armor Interface
#include "event.h"
#include <iostream>
#include <string>

class Armor : public Event {
    private:

    public:
        Armor();
        ~Armor();
        int interact(bool);
        void print_precept();


    
};

#endif