/**************************************************
 * Name: Airport class
 * Description: airport object
 ***********************************************/

#ifndef AIRPORT_H
#define AIRPORT_H 

#include <iostream>
#include <string>
#include <fstream>

#include "flight.h"

using namespace std;

class Airport
{
private:
	string name;		//airport name
	int num_flights;	//number of flights
	int cap;			//capacity
	Flight *f_arr;		//flight array

public:
/**************************************************
 * Name: Airport()
 * Description: defeault constructor
 * Parameters: n/a
 ***********************************************/
	Airport();

/**************************************************
 * Name: ~Airport()
 * Description: destructor
 * Parameters: n/a
 ***********************************************/
	~Airport();

/**************************************************
 * Name: ~Airport()
 * Description: destructor
 * Parameters: n/a
 ***********************************************/
	Airport(int);

/**************************************************
 * Name: Airport(const Airport&);
 * Description: copy constructor
 * Parameters: airport& - another airport object to copy over
 ***********************************************/
	Airport(const Airport&);

/**************************************************
 * Name: Airport& operator=(const Airport&)
 * Description: Opperator overload
 * Parameters: airport& another airport to copy over
 ***********************************************/
	Airport& operator=(const Airport&); 

/**************************************************
 * Name: populate_airport(ifstream& fin);
 * Description: Populate the airport
 * Parameters: input stream
 ***********************************************/
	void populate_airport(ifstream& fin);

/**************************************************
 * Name: add_a_flight(Flight& p)
 * Description: add_a_flight to things
 * Parameters: flight object
 ***********************************************/
	void add_a_flight(Flight& p);
/**************************************************
 * Name: remove a flight 
 * Description: Add a flight
 * Parameters: airport& another airport to copy over
 ***********************************************/
	Flight remove_a_flight(int idx);
/**************************************************
 * Name: Print airport
 * Description: print out an aiport 
 * Parameters: airport& another airport to copy over
 ***********************************************/
	void print_airport();

/**************************************************
 * Name: search_flight_by_name(string)
 * Description: gives the index by name
 * Parameters: airport& another airport to copy over
 ***********************************************/	
	int search_flight_by_name(string);

/**************************************************
 * Name: print_flight_by_name(string)
 * Description: prints out a flight 
 * Parameters: airport& another airport to copy over
 ***********************************************/	
	bool print_flight_by_name(string);

/**************************************************
 * Name: get_flight_at(int)
 * Description: get flight at an index
 * Parameters: airport& another airport to copy over
 ***********************************************/

	Flight get_flight_at(int);
/**************************************************
 * Name: get_flight_at(int)
 * Description: returns a flight
 * Parameters: airport& another airport to copy over
 ***********************************************/	
	int calc_dest_num(Airport*, int);

/**************************************************
 * Name: save_airport(ofstream)
 * Description: saves to a file 
 * Parameters: airport& another airport to copy over
 ***********************************************/
	void save_airport(ofstream&) const;





/**************************************************
 * Name: Setters and Getters
 * Description: The setters and getters for the airport classs
 * Parameters: Constants
 ***********************************************/


	void set_name(const string);
	string get_name() const;

	void set_num_flights(const int);
	void increment_num_flights();
	int get_num_flights() const;

	void set_cap(const int);
	int get_cap() const; 

	void set_f_arr(Flight *);
	void set_f_idx(Flight , const int);
	Flight* get_f_arr() const; 
	
};
#endif