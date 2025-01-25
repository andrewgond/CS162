#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream> 
#include "room.h"

using namespace std;

//Game interface 
class Game
{
private:
	
	//declare a 2D vector of Room objects:

	//other member variables:
	int side; 				//side of the board
	int num_arrows; 		//keep track of number of errors remaining
	bool debug_view;		//debug mode or not


	//feel free to add more variables...
	vector<vector<Room>> board;
	int adv_row;
	int adv_col;
	int oxygen; 


	int rope_row;
	int rope_col; 

	bool underwater;
	bool has_gold; 
	bool adv_dead;
	int hp;

public:

	//suggested functions:
	Game();
	~Game();
	
	void set_up(int);

	void display_game() const;

	bool check_win() const;

	char get_dir();
	void wumpus_move();
	void fire_arrow();

	void move_up();
	void move_down();
	void move_left();
	void move_right();
	void move(char);

	char get_input();

	void play_game(int, bool);

	string message;

	//feel free (and you will need) to add more functions...

/**************************************************
 * Name: place_events()
 * Description: place all the events
 * Parameters:  
***********************************************/
	void place_events();

/**************************************************
 * Name: place_adventurer()
 * Description: Places the adventerer
 * Parameters:
***********************************************/
	void place_adventurer();

/**************************************************
 * Name: check_valid_move(char c)
 * Description: Works as error handling so movements don't go out of bounds
 * Parameters:  Char c - type of movement
***********************************************/
	bool check_valid_move(char);

/**************************************************
 * Name: check_room();
 * Description: Checks the room the adventurer is on and does actions
 * Parameters:  
***********************************************/
	void check_room();

/**************************************************
 * Name: print_surrounding_precepts()
 * Description: Prints adjacent room's events
 * Parameters:  na
***********************************************/
	void print_surrounding_precepts();
	
/**************************************************
 * Name: find_wumpus_row()
 * Description: Finds the row where the wumpus is
 * Parameters:  
***********************************************/
	int find_wumpus_row();

/**************************************************
 * Name: find_wumpus_col()
 * Description: Finds the col where the wumpus is
 * Parameters:  
***********************************************/
	int find_wumpus_col();
	

/**************************************************
 * Name: euthanized_wumpus()
 * Description: arrow hit wumpus (Deletes the events at position)
 * Parameters:  int row, int col
***********************************************/
	void euthanize_wumpus(int,int);

/**************************************************
 * Name: prompt_play_again()
 * Description: prompt player to play again
 * Parameters:  na
***********************************************/
	int prompt_play_again();

/**************************************************
 * Name: prompt_for_int()
 * Description: error handling
 * Parameters:  string, int, int
***********************************************/
	int prompt_for_int(string, int, int);

/**************************************************
 * Name: hazard_interaction()
 * Description: hazards
 * Parameters:  na
***********************************************/
	void hazard_interaction();
};



#endif