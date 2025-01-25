#include "flight.h"

using namespace std;

Flight::Flight() {
	this->num_pilots = 0;
	this->pilots = NULL;
}

Flight::Flight(string flight_num, string curr_loc, string dest, int num_pilots, string* pilots){
	this->flight_num = flight_num;		//flight number
	this->curr_loc = curr_loc;			//current airport
	this-> dest = dest;					//destination 
	this-> num_pilots = num_pilots;		//number of pilots
	this->pilots = new string[this->num_pilots];
	for (int i = 0 ; i < this->num_pilots ; i++){
		this->pilots[i] = pilots[i];
	} 

}

Flight::Flight(int size){
	this->num_pilots = size;
	this->pilots = new string [size];
}



Flight::~Flight(){
	if (this->pilots != NULL){
		delete [] this->pilots;
		this->pilots = NULL;
	}
}




Flight::Flight(const Flight& f){
	this->flight_num = f.flight_num;
	this->curr_loc = f.curr_loc;
	this->dest = f.dest;
	this->num_pilots = f.num_pilots;

	this->flight_num = f.flight_num;

	this->pilots = new string[this->num_pilots];
	for (int i = 0 ; i < this->num_pilots ; i++){
		this->pilots[i] = f.pilots[i];
	}

}
	
Flight& Flight::operator=(const Flight& f){
	if (this == &f) return *this; 

	if (this->pilots != NULL) delete [] this->pilots;

	this->flight_num = f.flight_num;
	this->curr_loc = f.curr_loc;
	this->dest = f.dest;
	this->num_pilots = f.num_pilots;

	this->flight_num = f.flight_num;

	this->pilots = new string[this->num_pilots];
	for (int i = 0 ; i < this->num_pilots ; i++){
		this->pilots[i] = f.pilots[i];
	}
	return *this;

}





void Flight::populate_flight(ifstream& fin) {
	//Your code goes here:
	fin >> this->flight_num;
	fin >> this->curr_loc;
	fin >> this ->dest;
	fin >> this->num_pilots;
	this->pilots = new string[this->num_pilots];
	for (int i = 0 ; i < this->num_pilots ; i++){
		fin >> this->pilots[i];
	}
	return;
}

void Flight::print_flight() const{
	//Your code goes here:
	cout << "Flight num: " << this->flight_num << " | Current Location: " << this->curr_loc << " | Destination: " << this->dest << " | Number of Pilots: " << this->num_pilots;
	cout << " | Pilots : "; 
	for (int i = 0 ; i < this->num_pilots ; i++)
	{
		cout << this->pilots[i];
		if (!(i+1 == this->num_pilots)) cout << ", ";
	}
	cout << endl; 
	return;
}

void Flight::save_flight(ofstream& output_file) const{
	output_file << this->flight_num << " " 
				<< this->curr_loc << " "
				<< this->dest << " "
				<< this->num_pilots << " ";
	for (int i = 0 ; i < num_pilots ; i++){
		output_file << this->pilots[i] << " ";
	}
}













/* ======================== 
 *  ACCESSORS AND MUTATORS
*/

void Flight::set_flight_num(const string flight_num){
	this->flight_num = flight_num;
}

string Flight::get_flight_num () const{
	return (this->flight_num);
}

void Flight::set_curr_loc (const string curr_loc){
	this->curr_loc = curr_loc; 
}

string Flight::get_curr_loc () const{
	return (this->curr_loc);
}

void Flight::set_dest(const string dest){
	this->dest = dest;
}

string Flight::get_dest() const{
	return (this->dest);
}

void Flight::set_num_pilots(const int num_pilots){
	this->num_pilots = num_pilots;
}

int Flight::get_num_pilots() const{
	return (this->num_pilots);
}

void Flight::set_pilots( string* pilots){
	this->pilots = pilots;
}

string* Flight::get_pilots() const{
	return (this->pilots);
}



