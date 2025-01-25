#include "stalactites.h"

#include <iostream>

using namespace std;

//Stalactites Implementation
Stalactites::Stalactites() : Event(){
    this->debug_symbol = 'S';
}

Stalactites::~Stalactites(){

}

int Stalactites::interact(bool u){
    if (u){
        //If underwater does not interact
        cout << "You hear water dripping above you." << endl;
        return -1;
    }
    int r = rand()%2;
    if (r == 0) {  
        //cout << "A stalactite falls on you." << endl;
        return 0;
    }
    else return -1;
}

void Stalactites::print_precept(){
    cout << "You hear water dripping." << endl;
}

