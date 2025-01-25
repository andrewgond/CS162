#include "wumpus.h"

#include <iostream>

using namespace std;

//Wumpus Implementation
Wumpus::Wumpus() : Event(){
    this->debug_symbol = 'W';
}

Wumpus::~Wumpus(){

}

int Wumpus::interact(bool u){
    if (u){
        //If underwater does not interact
        cout << "There's a horrible stench above you" << endl;
        return -1;
    }
    else {
        //cout << "You have woken up the wumpus" <<endl;
        return 0;
    }
}

void Wumpus::print_precept(){
    cout << "There's a horrible stench" << endl;
}
