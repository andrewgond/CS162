#include "gold.h"

#include <iostream>

using namespace std;

//Gold Implementation
Gold::Gold() : Event(){
    this->debug_symbol = 'G';
}

Gold::~Gold(){

}

int Gold::interact(bool u){
    if (u){
        //If underwater does not interact
        cout << "You see gold shimmer above you" << endl;
        return -1;
    }
    else {
        //cout << "You have picked up the gold" << endl;
        return 1;
    }
}

void Gold::print_precept(){
    cout << "You see a glimmer nearby." << endl;
}
