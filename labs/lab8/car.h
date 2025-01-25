#ifndef CAR_H
#define CAR_H

#include "vehicle.h"
#include <string>

class Car : public Vehicle {
    private:
        int num_door;
        bool electric; // true if powered by electricity, false otherwise
    public:
        Car();
        ~Car();

        void set_electric(const bool);

        void print_info();
        int gas_price();

};

#endif