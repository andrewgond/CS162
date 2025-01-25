#include "room.h"

using namespace std;

/**
 * Constructors and BIG 3
*/

Room::Room(){
    has_adventurer = false;
    has_event = false;
    e = nullptr;
}

Room::~Room(){
    if (!(e == nullptr)){
        delete e;
    }
}

Room& Room::operator=(const Room& r){
	if (this == &r) return *this; 
    this->has_adventurer = r.get_has_adventurer();
    this->has_event = r.get_has_event();
    this->e = r.get_event();
    return *this;

}

Room::Room(const Room& r){
    this->has_adventurer = r.get_has_adventurer();
    this->has_event = r.get_has_event();
    this->e = r.get_event();
}

//Room Implementation

/**
 * Getters
*/

bool Room::get_has_adventurer() const{
    return this->has_adventurer;
}
bool Room::get_has_event() const{
    return this->has_event;
}
Event* Room::get_event() const{
    return this->e;
}

/**
 * Setters
*/
void Room::set_has_adventurer(const bool has){
    this->has_adventurer = has; 
}
void Room::set_has_event(const bool has){
    this->has_event = has; 
}
void Room::set_event(Event* event_ptr){
    this->e = event_ptr;
    set_has_event(true);
}