#include "game.h"
#include "gold.h"
#include "stalactites.h"
#include "pool.h"
#include "armor.h"
#include "wumpus.h"

#include <iostream>

using namespace std;

//Game Implementation

Game::Game(){
	//Game constructor
	//Your code here:
}

Game::~Game(){
	//Game destructor
	//Your code here:

}


void Game::set_up(int s){
	//set up the game
	this->side = s;

	this->num_arrows = 3; 	//start with 3 arrows
	this->oxygen = this->side * 2;
	this->underwater = false;
	this->has_gold = false; 
	this->adv_dead = false;
	this->hp = 1;
	this->message = "";
	// Finish the remaining...
	//Your code here:
	
	// Create the game board: 2D vector of Room objects
	for (int x = 0; x < side; x++)
    {
        for (int y = 0; y < side; y++)
        {
            board.push_back(vector <Room> ()); // make more rows
            board[x].push_back(Room()); // add to the columns
        }
    }
	// randomly insert events (2 pool accesses, 2 stalactites, 1 wumpus, 1 gold)
	// into the board
	//vector<Event*> events = {new Pool(), new Pool(), new Stalactites(), new Stalactites(), new Wumpus(), new Gold()};
	place_events();

	//place Adventurer
	place_adventurer();

}

//Note: you need to modify this function
void Game::display_game() const{
	//Longer than 15 lines because a lot of print statements and just formatting
	cout << endl << endl;
	cout << "Arrows remaining: " << this->num_arrows << endl;

	//print oxygen level:
	cout << "Oxygen Level: " << this->oxygen << endl;

	//print Underwater?:
	if (this->underwater) cout << "Status: Underwater" << endl;
	if (this->hp>1) cout << "Armor: " << this->hp-1 << endl;
	string line = "";
	for (int i = 0; i < this->side; ++i)
		line += "-----";
	for (int i = 0; i < this->side; ++i)
	{
		cout << line << endl;
		for (int j = 0; j < this->side; ++j)
		{
			if (board[i][j].get_has_adventurer()) cout << "*" ;
			else cout << " " ;
			if (i == rope_row && j == rope_col && debug_view) cout << "~ ||";
			else if (!board[i][j].get_has_event()) cout << "  ||";
			else {
				if (debug_view) cout << board[i][j].get_event()->get_debug_symbol();
				else {
					cout << " ";
				}
				cout << " ||";
			}
		}
		cout << endl;
	}
	cout << line << endl;

	//example output (when finished): 
	// --------------------
	//  P || G || P ||   ||
	// --------------------
	//    || W ||   || S ||
	// --------------------   
	//    ||   ||   || S ||
	// --------------------   
	// *  ||   ||   ||   ||
	// --------------------
}

bool Game::check_win() const{
	//check if game over/win
	//Your code here:
	return (this->has_gold && this->adv_col == this->rope_col &&  this->adv_row == this->rope_row && !this->underwater);
}

void Game::move_up() {
	//move player up
	//Your code here:
	int temp_row = this->adv_row;
	int temp_col = this->adv_col;

	this->board[temp_row][temp_col].set_has_adventurer(false);
	this->adv_row--;
	this->board[adv_row][adv_col].set_has_adventurer(true);
	cout << "Aventurer has moved up." << endl;
	return;

}

void Game::move_down() {
	//move player down
	//Your code here:
	int temp_row = this->adv_row;
	int temp_col = this->adv_col;

	this->board[temp_row][temp_col].set_has_adventurer(false);
	this->adv_row++;
	this->board[adv_row][adv_col].set_has_adventurer(true);
	cout << "Aventurer has moved down." << endl;
	return;
}

void Game::move_left() {
	//move player left
	//Your code here:
	int temp_row = this->adv_row;
	int temp_col = this->adv_col;

	this->board[temp_row][temp_col].set_has_adventurer(false);
	this->adv_col--;
	this->board[adv_row][adv_col].set_has_adventurer(true);
	cout << "Aventurer has moved left." << endl;
	return;

}

void Game::move_right() {
	//move player right
	//Your code here:
	int temp_row = this->adv_row;
	int temp_col = this->adv_col;

	this->board[temp_row][temp_col].set_has_adventurer(false);
	this->adv_col++;
	this->board[adv_row][adv_col].set_has_adventurer(true);
	cout << "Aventurer has moved right." << endl;
	return;
}

char Game::get_dir(){
	//get direction of arrow:
	char dir;
	//Note: error checking is needed!! 
	//Your code here:
	bool valid = false;
	do {
		cout << "Fire an arrow...." << endl;
		cout << "W-up" << endl;
		cout << "A-left" << endl;
		cout << "S-down" << endl;
		cout << "D-right" << endl;
			
		
		cout << "Enter direction: " << endl;
		cin >> dir;
		cin.ignore(256, '\n');

		if (!(dir == 'w' || dir == 'a' || dir == 's' || dir == 'd' || dir == 'f')) {
			valid = false;
			cout << "Invalid input" << endl << endl;
		}
		else valid = true;
	} while (!valid);
	return dir;
}

void Game::wumpus_move(){
	//after a missed arrow, 75% chance that the wumpus is moved to a different room

	//How to get 75%? 
	//Hint: generate a random number from 0-3, if the number is not 0, then move
	int move = rand()%4 ; // decides if its moving or not
	int wumpus_row = find_wumpus_row();
	int wumpus_col = find_wumpus_col();
	if (move > 0){
		int col = 0;
		int row = 0;
		do {
			col = rand()%this->side;
			row = rand()%this->side;
		} while (board[row][col].get_has_event());
		board[row][col].set_event(new Wumpus());
		euthanize_wumpus(wumpus_row,wumpus_col);

	}	
	return;
}

void Game::fire_arrow(){
	// The player may fire arrow...
	char dir = get_dir();
	bool wumpus_hit = 0; 
	//FIND THE WUMPUS
	int wumpus_row = find_wumpus_row();
	int wumpus_col = find_wumpus_col();
	if (wumpus_col == -1){ // wumpus not exist D:
		this->message = "No wumpus to hunt.. Arrow flies off to nothing \n";
		return;
	}
	//Your code here:
	//cout << "Game::fire_arrow() is not implemented..." << endl;
	int arrow_row = this->adv_row;
	int arrow_col = this->adv_col;
	this->num_arrows --;
	for (int i = 0 ; i < 3 ; i++){
		if (dir == 'w') arrow_row --;
		else if (dir == 'a') arrow_col--;
		else if (dir == 's') arrow_row++;
		else if (dir == 'd') arrow_col++;

		if (arrow_col < 0 || arrow_row < 0 || arrow_row >= this->side || arrow_col >= this->side){
			this->message = "Arrow has hit a wall\n";
			wumpus_move();
			return;
		}
		else if (arrow_row == wumpus_row && arrow_col == wumpus_col){
			this->message = "Wumpus has been hunted!!!\n";
			euthanize_wumpus(wumpus_row,wumpus_col);
			return;
		}
	}
	Game::wumpus_move();

	this->message = "Arrow has missed\n"; 

	return;

}

void Game::move(char c) {
	// Handle player's action: move or fire an arrow
	if (c == 'f'){
		Game::fire_arrow();
		return;
	}
	switch(c){
		case 'w':
			Game::move_up();
			break;
		case 'a':
			Game::move_left();
			break;
		case 's':
			Game::move_down();
			break;
		case 'd':
			Game::move_right();
			break;
	}
}

char Game::get_input(){
	//get action, move direction or firing an arrow

	//Note: error checking is needed!!
	//Your code here:
	char c;
	bool valid = true;
	do {
	cout << endl << endl << "Player move..." << endl << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	cout << "f-fire an arrow" << endl;

	cout << "Enter input: " << endl;
	cin >> c;
	cin.ignore(256, '\n');

	//ERROR HANDLING DOWN HERE 
	if (!(c == 'w' || c == 'a' || c == 's' || c == 'd' || c == 'f')) {
		valid = false;
	}
	else if (c == 'f' && this->underwater)valid = true;
	else if (c == 'f' && this->num_arrows <= 0){
		cout << "Out of arrows!" << endl;
		valid = true;
	}
	else if (Game::check_valid_move(c)) valid = true;
	else valid = false; // Alternative if move is out of bounds
	if (valid) {
		cout << endl << "Invalid Input! Retry-" <<endl;
		Game::display_game();
	}
	} while (valid);
	
	return c;
}

//Note: you need to modify this function
void Game::play_game(int s, bool d){
	// 
	int play_again = 0;
	do
	{
		if (play_again == 2){
			s = prompt_for_int("Side Length of Cave 4-50: ", 4,50);
			d = (prompt_for_int("Debug mode: 0-false, 1-true ", 0,1) == 1);
		}
		Game::set_up(s);
		this->debug_view = d;

		char input, arrow_input;
		int move_count = 0;
		
		while (Game::check_win() == false){
			
			
			//print game board
			Game::display_game();
			cout << this->message;
			this->message = "";
			//display percerts around player's location
			//Your code here:
			Game::print_surrounding_precepts();

			//Player move...
			//1. get input
			input = Game::get_input();
			//2. move player
			Game::move(input);
			//3. may or may not encounter events
			//Your code here:
			Game::check_room();
			move_count++;
			
			if (this->underwater){
				this->oxygen --;
				if (this->oxygen <= 0){
					Game::display_game();
					cout << "You have drowned... \nYou have lost..." << endl;
					adv_dead = true;
					break;
				}
			}
			if (Game::check_win()){
				Game::display_game();
				cout << endl << "YOU HAVE WON!!" << endl << endl;
			}
			else if (this->adv_dead){
				Game::display_game();
				cout << message << endl << endl;
				break;
			}
		}
		for (int i = 0  ; i < this->side ; i++) this->board[i].clear();
		this->board.clear();
		play_again = prompt_play_again();
	} while (play_again != 0);
	return;

}

bool Game::check_valid_move(char c){
	int temp_col = this->adv_col;
	int temp_row = this->adv_row;
	//Move to see the temp row if it would go out of bounds
	if (c == 'w') temp_row--;
	else if (c == 'a') temp_col--;
	else if (c == 's') temp_row++;
	else if (c == 'd') temp_col++;

	//Check if it would go out of bounds
	return (temp_col < 0 || temp_row < 0 || temp_row >= this->side || temp_col >= this->side);
}

void Game::check_room(){
	int interaction = -1;
	if (this->board[this->adv_row][this->adv_col].get_has_event()){
		interaction = this->board[this->adv_row][this->adv_col].get_event()->interact(underwater);
		// Basically if there's an event the inraction will be done here based on the output from the 
		// type of event
	}
	if (interaction == 0){
		//cout << "YOU HAVE LOST";
		Game::hazard_interaction();
		return; 
	}
	else if (interaction == 1){
		this->has_gold = true;
		euthanize_wumpus(this->adv_row,this->adv_col);
		this->message = "You have picked up the gold\n";
		//cout << "HAS GOLD?: " << has_gold;
	}
	else if (interaction == 2){
		if (this->underwater) {
			this->underwater = false;
			this->oxygen = this->side * 2;
		}
		else {
			this->underwater = true;
		}
	}
	else if (interaction == 3){
		this->hp = 3; 
		euthanize_wumpus(this->adv_row,this->adv_col);
		this->message = "You have picked up armor\n";
	}
	return;
}

void Game::print_surrounding_precepts() {
	// Not optimal but not too long if we dont include curly brackets..
	if (!check_valid_move('w')) //Check for Precept above
	{
		if (board[this->adv_row-1][this->adv_col].get_has_event()){
		board[this->adv_row-1][this->adv_col].get_event()->print_precept();	
		}
	} 
	if (!check_valid_move('a'))//Check for Precept left
	{
		if (board[this->adv_row][this->adv_col-1].get_has_event()){
			board[this->adv_row][this->adv_col-1].get_event()->print_precept();	
		}
	}
	if (!check_valid_move('s')) //Check for Precept down
	{
		if (board[this->adv_row+1][this->adv_col].get_has_event()){
			board[this->adv_row+1][this->adv_col].get_event()->print_precept();	
		}
	}
	if (!check_valid_move('d')) //Check for Precept right
	{
		if (board[this->adv_row][this->adv_col+1].get_has_event()){
			board[this->adv_row][this->adv_col+1].get_event()->print_precept();	
		}
	}
	
}


int Game::find_wumpus_row(){
	// finds the location of wumpus and returns row
	for (int r = 0 ; r < this->side ; r++){
		for (int c = 0 ; c < this->side ; c++){
			if (board[r][c].get_has_event())
			{
				if (board[r][c].get_event()->get_debug_symbol() == 'W'){
					return r; 
				}
			}
		}
	}
	return -1;
}

int Game::find_wumpus_col(){
	// finds the location of wumpus and returns col
	for (int r = 0 ; r < this->side ; r++){
		for (int c = 0 ; c < this->side ; c++){
			if (board[r][c].get_has_event())
			{
				if (board[r][c].get_event()->get_debug_symbol() == 'W'){
					return c; 
				}
			}
		}
	}
	return -1;
}


void Game::place_events(){
	int num_events = 7;
	for (int i = 0 ; i < num_events; i++){
		int x = 0;
		int y = 0;
		do { //Making sure there's no double event
			x = rand()%this->side;
			y = rand()%this->side;
		} while (board[y][x].get_has_event());
		//cout << "Board at: " << x << ", " << y << endl;
		// For inserting events
		Event* insert_event;
		if (i == 6) insert_event = new Armor();
		else if (i>3) insert_event = new Pool();
		else if (i>1) insert_event = new Stalactites();
		else if (i==1) insert_event = new Wumpus();
		else if (i==0) insert_event = new Gold();
		board[y][x].set_event(insert_event);
		
	}
}


void Game::place_adventurer(){
	int row = 0;
	int col = 0;
	do {
		row = rand()%this->side;
		col = rand()%this->side;
	} while (board[row][col].get_has_event());
	//Random spot not on any event
	this->adv_row = row;
	this->adv_col = col;
	board[row][col].set_has_adventurer(true);
	//places rope
	this->rope_col = col;
	this->rope_row = row;	
	cout << this->rope_col;
}

void Game::euthanize_wumpus(int row, int col){
	//Clears the memory for events and the room
	delete this->board[row][col].get_event();
	this->board[row][col].set_event(nullptr);
	this->board[row][col].set_has_event(false);
}

int Game::prompt_play_again(){
	string prompt = "\nPlay again?\n0 - Quit Game\n1 - Play again same cave configuration\n2 - Start over with a new cave configuration\n";
	return prompt_for_int(prompt , 0, 2);
}

int Game::prompt_for_int(string request , int min, int max)
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

void Game::hazard_interaction(){
	this->hp--; //HP system for armor
	if (this->adv_col == find_wumpus_col() && this->adv_row == find_wumpus_row()){
		this->message = "You have woken the wumpus..\n";
	}
	else this->message = "A stalactite falls on you.\n";

	// Extra credit armor
	if (hp < 1){
		this->adv_dead = true;
		this->message = this->message + "You have lost...";
	}
}