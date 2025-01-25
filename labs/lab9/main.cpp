#include <iostream>
#include <vector>
#include "vehicle.h"
#include "car.h"
#include "bus.h"


using namespace std;

void print_vehicle_info (Vehicle &);

int main()
{
    vector <Vehicle *> vehicle_vec;

    for (int i = 0; i < 10; i++)
    {
        if ((i % 2)==0){
           vehicle_vec.push_back(new Bus("School",2000+i,i*10.0,2));
        }
        else {
            vehicle_vec.push_back(new Car("Subaru",2000+i, i*10, 4, false));
        }
    }
    
    for (int i = 0; i < 10 ; i++) print_vehicle_info(*(vehicle_vec[i]));
    for (int i = 0; i < 10 ; i++) delete vehicle_vec[i];
	return 0;
}

void print_vehicle_info (Vehicle &v){
    v.print_info();
}