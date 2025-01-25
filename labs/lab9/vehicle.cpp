#include "vehicle.h"

using namespace std;
        
Vehicle::Vehicle() : brand("NA"){
    year = 0;
    mileage = 10.0;
}

Vehicle::Vehicle(string b, int y, double m) : brand(b){
    year = y;
    mileage = m;
}

Vehicle::~Vehicle(){
}




int Vehicle::get_year() const {
    return this->year;
}
double Vehicle::get_milage() const {
    return this->mileage;
}
void Vehicle::set_year(const int y) {
    this->year = y;
}
void Vehicle::set_milage(const double m) {
    this->year = m;
}