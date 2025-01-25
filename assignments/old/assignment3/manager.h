/**************************************************
 * Name: Manager class
 * Description: manager object
 ***********************************************/
#ifndef MANAGER_H
#define MANAGER_H 

#include "airport.h"
#include <iostream>
#include <fstream>

using namespace std;

class Manager
{
private:
	int num_airports;	//number of airports
	Airport* a_arr;		//airport array

public:

/*************************************************
 * Name: Manager()
 * Description: All the constructors and big 3
 * Parameters: na
 ***********************************************/
	Manager();
	~Manager();

	void populate(ifstream& fin);

/*************************************************
 * Name: init()
 * Description:  Initalizes everything from the thing
 * Parameters: na
 ***********************************************/
	int init();
	
/*************************************************
 * Name: print_menu()
 * Description: prints menu for the user to choose
 * Parameters: na
 ***********************************************/
	void print_menu();

/*************************************************
 * Name: get_menu_choice()
 * Description: makes usre things work and choice is chosen.
 * Parameters: na
 ***********************************************/
	int get_menu_choice();
	
	
	void print_all();
	/*************************************************
 * Name: simulate_all_control()
 * Description: moves all the planes
 * Parameters: na
 ***********************************************/
	void check_flight_control();

/*************************************************
 * Name: add_flight_controll()
 * Description: adds a flight 
 * Parameters: na
 ***********************************************/
	void add_flight_control();

/*************************************************
 * Name: cancel_flight_control()
 * Description: cancels a flight
 * Parameters: na
 ***********************************************/
	void cancel_flight_control();
	
/*************************************************
 * Name: take_off_control()
 * Description: tkae of a single plane
 * Parameters: na
 ***********************************************/
	void take_off_control();

/*************************************************
 * Name: stats_control()
 * Description: displays the stats
 * Parameters: na
 ***********************************************/
	void stats_control();

/*************************************************
 * Name: simulate_all_control()
 * Description: moves all the planes
 * Parameters: na
 ***********************************************/
	void simulate_all_control();
	
/**************************************************
 * Name: run()
 * Description: runs the main things
 * Parameters: na
 ***********************************************/
	void run();


	/**************************************************
	 * Name: prompt_for_choice()
	 * Description: Works as error handling and prompting
	 * Parameters: String with prompt/request, and min/max domain for int
	 * Pre-conditions: User input is an integer
	 * Post-conditions: an int that matches the requirements
	 ***********************************************/
	int prompt_for_choice(int , int);

	/**************************************************
	 * Name: prompt_for_int()
	 * Description: Works as error handling and prompting
	 * Parameters: String with prompt/request, and min/max domain for int
	 * Pre-conditions: User input is an integer
	 * Post-conditions: an int that matches the requirements
	 ***********************************************/
	int prompt_for_int(string, int, int);
	
/**************************************************
 * Name: prompt_for_new_flight
 * Description: Ask user questions for making a new flight
 * Parameters: String with prompt/request, and min/max domain for int
 * Pre-conditions: User input is an integer
 * Post-conditions: an int that matches the requirements
 ***********************************************/
	Flight prompt_for_new_flight(string);

/**************************************************
 * Name: check_over_cap(Airport*, int)
 * Description: check if the destinations are over the top
 * Parameters: String with prompt/request, and min/max domain for int
 * Pre-conditions: User input is an integer
 * Post-conditions: an int that matches the requirements
 ***********************************************/
	bool check_over_cap(Airport*, int);

/**************************************************
 * Name: clac_total_flights(airport*, int )
 * Description: Works as error handling and prompting
 * Parameters: String with prompt/request, and min/max domain for int
 * Pre-conditions: User input is an integer
 * Post-conditions: an int that matches the requirements
 ***********************************************/
	int calc_total_flights(Airport*, int );

/**************************************************
 * Name:  just_flights(int)
 * Description: 
 * Parameters: String with prompt/request, and min/max domain for int
 * Pre-conditions: User input is an integer
 * Post-conditions: an int that matches the requirements
 ***********************************************/
	Flight *just_flights(int );

/**************************************************
 * Name: prompt_for_int()
 * Description: Works as error handling and prompting
 * Parameters: String with prompt/request, and min/max domain for int
 * Pre-conditions: User input is an integer
 * Post-conditions: an int that matches the requirements
 ***********************************************/
	void update_file();
	
};
#endif