/******************************************************
** Program: wumpus.cpp
** Author: Andrew Gondoputro
** Date: 3/17/2024
** Description: HUNT THE WUMOUS GAME!!! (More in the README.txt)
** Input: User inputs
** Output: Terminal screen game
******************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;

int prompt_for_int(string,int,int);

int main()
{
	//set the random seed
	srand(time(NULL));
	
	//side length: hardcoded value for now
	int side_len = 5;
	bool debug = false;
	
	Game g;

	//get one input: side length of the cave
	side_len = prompt_for_int("Side Length of Cave 4-50: ", 4,50);


	//get the 2nd input --> debug mode or not
	debug = (prompt_for_int("Debug mode: 0-false, 1-true ", 0,1) == 1);

	//Play game
	g.play_game(side_len, debug);


	return 0;
}

/**************************************************
 * Name: prompt_for_int()
 * Description: Works as error handling and prompting
 * Parameters: String with prompt/request, and min/max domain for int
 * Pre-conditions: User input is an integer
 * Post-conditions: an int that matches the requirements
 ***********************************************/
int prompt_for_int(string request , int min, int max)
{
	int output; 
	do {
		//Checks if the input stream previously failed or not and resets it
		if (cin.fail()){
			cin.clear(); 
			cin.ignore(1000000,'\n');
		}
		cout << request; 
		cin >> output; 
		if (output < min || output > max || cin.fail()) cout << "Invalid Input" << endl; //States error
	} while (output < min || output > max || cin.fail());
	return output;
}