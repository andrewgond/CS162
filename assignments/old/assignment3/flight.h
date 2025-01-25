#ifndef FLIGHT_H
#define FLIGHT_H 

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Flight
{
private: 
	string flight_num;		//flight number
	string curr_loc;		//current airport
	string dest;			//destination 
	int num_pilots;			//number of pilots
	string* pilots;			//pilot array

public:
/**************************************************
 * Name: Flight()
 * Description: Defeault constructor
 * Parameters: 
 ***********************************************/
	Flight();

/**************************************************
 * Name: Flight(string, string, string, int, string*)
 * Description: creates a flight with every variable
 * Parameters: flight num, curr_loc, dest, num_pilots
 ***********************************************/
	Flight(string, string, string, int, string*);

/**************************************************
 * Name: Flight(int)
 * Description: makes a flight with just the int
 * Parameters: 
 ***********************************************/
	Flight(int);

/**************************************************
 * Name: ~Flight()
 * Description: destructor constructor
 * Parameters: na
 ***********************************************/
	~Flight();

/**************************************************
 * Name: Flight(cosnt Flight&)
 * Description: copy constructor
 * Parameters: 
 ***********************************************/
	Flight(const Flight&);

/**************************************************
 * Name: operator=(const flight&)
 * Description: Defeault constructor
 * Parameters: 
 ***********************************************/
	Flight& operator=(const Flight&); 
	
/**************************************************
 * Name: populate_flight()
 * Description: populates a flight from the input file
 * Parameters: ifstream&
 ***********************************************/
	void populate_flight(ifstream&);

/**************************************************
 * Name: print_flight()
 * Description: populates a flight from the input file
 * Parameters: ifstream&
 ***********************************************/
	void print_flight() const;

	void save_flight(ofstream&) const;



/**************************************************
 * Name: Setters and Getters
 * Description: The setters and getters for the flight classs
 * Parameters: Constants
 ***********************************************/

	void set_flight_num(const string);
	string get_flight_num () const;

	void set_curr_loc (const string);
	string get_curr_loc () const;
	
	void set_dest(const string);
	string get_dest() const;

	void set_num_pilots(const int);
	int get_num_pilots() const;

	void set_pilots(string*);
	string* get_pilots() const;

	
	
};

#endif
