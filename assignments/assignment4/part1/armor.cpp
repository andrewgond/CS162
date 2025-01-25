#include "armor.h"

#include <iostream>

using namespace std;

//Armor Implementation
Armor::Armor() : Event(){
    this->debug_symbol = 'A';
}

Armor::~Armor(){

}

int Armor::interact(bool u){
    if (u){
        cout << "You feel the power above you" << endl;
        return -1;
    }
    return 3;
}

void Armor::print_precept(){
    cout << "You feel the power." << endl;
}