#include "car.h"

using namespace std; 

Car::Car() : Vehicle() {
    num_door = 4;
    electric = false;
}

Car::Car(string b, int y, double m, int d, bool e) : Vehicle(b,y,m){
    
}

Car::~Car(){

}


void Car::print_info(){
    cout << "Brand: " << this->brand 
    << " | Year: " << this->year 
    << " | Milage: " << this->mileage
    << " | Number of Doors: " << this->num_door
    << " | Vehicle type: " <<endl;

    // if (electric) cout << "Electric Vehicle";
    // else cout << "Gas Vehicle"; 

    cout << " | Gas Price: " << gas_price() << endl;
}

int Car::gas_price(){
    // if (electric) return (this->mileage * 0.05);
    // else return (this->mileage *0.35);
     return (this->mileage *0.35);
}

void Car::set_electric(const bool a){
    this->electric = a;
}