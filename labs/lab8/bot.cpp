#include "bot.h"

using namespace std; 

Delivery_Bot::Delivery_Bot() : Car(){
    Delivery_Bot::set_electric(true);
}

void Delivery_Bot::set_electric(bool a){
    Car::set_electric(a);
}
