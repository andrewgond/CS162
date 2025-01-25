#include <iostream>
#include "vehicle.h"
#include "car.h"
#include "bus.h"
#include "bot.h"

using namespace std;

int main()
{
    cout << " Vehicle: " << endl;
	Vehicle v;
	v.print_info();


    cout << endl << "Bus: " << endl;
    Bus b;
    b.print_info();
    cout << "Gas Cost: " << b.gas_price() << endl;

    
    cout << endl << "Car: " << endl;
    Car c;
    c.print_info();
    cout << "Gas Cost: " << c.gas_price();

/*
    cout << "Bot: " << endl;
    Delivery_Bot d;
    d.print_info();
*/
	return 0;
}