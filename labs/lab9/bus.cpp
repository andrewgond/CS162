#include "bus.h"

using namespace std; 

Bus::Bus() : Vehicle() {
    seat_capcity = 10;
}

Bus::Bus(string b, int y, double m, int s) : Vehicle(b,y,m){
    seat_capcity = s;
}

Bus::~Bus(){

}


void Bus::print_info(){
    cout << "Brand: " << this->brand 
    << " | Year: " << this->year 
    << " | Milage: " << this->mileage
    << " | Number of Seats: " << seat_capcity
    << " | Gas Price: " << gas_price() << endl ;
}

int Bus::gas_price(){
    return (this->mileage*0.5);
}
