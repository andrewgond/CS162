#include "bus.h"

using namespace std; 

Bus::Bus() : Vehicle() {
    int seat_capacity = 10;
}

Bus::~Bus(){

}


void Bus::print_info(){
    Vehicle::print_info(); 
    cout <<"Number of Seats: " << seat_capcity << endl ;
}

int Bus::gas_price(){
    return (this->mileage*0.5);
}
