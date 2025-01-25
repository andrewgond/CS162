#ifndef VEHICLE_H
#define VEHICLE_H


#include <iostream>
#include <string>

using namespace std; 
class Vehicle {
    protected:
        const string brand; //note the keyword ‘const’
        int year;
        double mileage;
    public:
        Vehicle();
        ~Vehicle();

        void print_info();
        int gas_price();


};

#endif
