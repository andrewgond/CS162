#include "car.h"

using namespace std; 

Car::Car() : Vehicle() {
    int num_door = 4;
    bool electric = false;
}

Car::~Car(){

}


void Car::print_info(){
    Vehicle::print_info(); 
    cout <<"Number of Doors: " << num_door;

    if (electric) cout << " Electric Vehicle" << endl;
    else cout << " Gas Vehicle" << endl; 
}

int Car::gas_price(){
    if (electric) return (this->mileage * 0.05);
    else return (this->mileage *0.35);
}

void Car::set_electric(const bool a){
    this->electric = a;
}