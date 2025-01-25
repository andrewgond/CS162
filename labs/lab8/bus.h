#ifndef BUS_H
#define BUS_H

#include "vehicle.h"
#include <iostream>
#include <string>

class Bus : public Vehicle {
    private:
        int seat_capcity;
    public:
        Bus();
        ~Bus();
        void print_info();
        int gas_price();
};

#endif