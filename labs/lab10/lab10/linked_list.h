#ifndef LINKED_LIST
#define LINKED_LIST

#include "node.h"
#include <iostream>

using namespace std;

class Linked_List {
private:
	int length; // the number of nodes contained in the list
	Node* head; // a pointer to the first node in the list
	// anything else you need...
public:

	int get_length();
	// note: there is no set_length(unsigned int) (the reasoning should be intuitive)
   
	void print(); // output a list of all integers contained within the list
	void clear(); // delete the entire list (remove all nodes and reset length to 0)
   
	void push_front(int); // insert a new value at the front of the list 
	void pop_front(); // remove the node at the front of the list

	// you can add extra member variables or functions as desired

};




#endif
