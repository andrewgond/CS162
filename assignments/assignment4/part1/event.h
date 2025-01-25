#ifndef EVENT_H
#define EVENT_H 

using namespace std;

//Event Interface
//Note: this must be an abstract class!

class Event
{

protected:
    char debug_symbol;
	

public:

	virtual void print_precept() = 0;
	virtual int interact(bool) = 0;
    char get_debug_symbol() const;
};
#endif