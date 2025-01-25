#ifndef BOT_H
#define BOT_H

#include "car.h"

class Delivery_Bot : public Car {
public:
    Delivery_Bot();
    //~Delivery_Bot();

    void set_electric(bool);

};

#endif
