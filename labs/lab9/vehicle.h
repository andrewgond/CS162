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
        Vehicle(string, int, double);
        ~Vehicle();

        int get_year() const;
        double get_milage() const;

        void set_year(const int);
        void set_milage(const double);

        virtual void print_info() = 0;
        virtual int gas_price() = 0;


};

#endif
