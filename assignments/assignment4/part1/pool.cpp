#include "pool.h"

#include <iostream>

using namespace std;

//Pool Implementation
Pool::Pool() : Event(){
    this->debug_symbol = 'P';
}

Pool::~Pool(){

}

int Pool::interact(bool u){
    return 2;
}

void Pool::print_precept(){
    cout << "You hear wind blowing." << endl;
}