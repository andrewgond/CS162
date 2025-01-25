#include "vehicle.h"

using namespace std;
        
Vehicle::Vehicle() : brand("Subaru"){
    year = 0;
    mileage = 10.0;
}

Vehicle::~Vehicle(){
}


void Vehicle::print_info(){
    cout << "Brand: " << this->brand << " Year: " << this->year << " Milage: " << this->mileage << endl; 
}

int Vehicle::gas_price(){
    return 0;
}