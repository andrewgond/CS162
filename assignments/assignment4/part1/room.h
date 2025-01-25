#ifndef ROOM_H
#define ROOM_H 

#include "event.h"

using namespace std;

//Room Interface
//Note: Each room may be empty or has an event (bat, gold, pit, or wumpus);
//		Use event polymorphically

class Room
{
private: 

    bool has_adventurer;
    bool has_event;
	Event *e;

public:
	Room();
    ~Room();
    Room& operator=(const Room&);
    Room(const Room&);


    //GETTERS and SETTERs

    bool get_has_adventurer() const;
    bool get_has_event() const;
    Event* get_event() const;


    void set_has_adventurer(const bool);
    void set_has_event(const bool);
    void set_event(Event *);

};

#endif