#include "airport.h"

using namespace std;

Airport::Airport() {
	
}

Airport::~Airport(){
	if (this->f_arr != NULL){
		delete [] this->f_arr;
		this->f_arr = NULL;
	}
}


Airport::Airport(int size){
	this->cap = size;
	this->f_arr = new Flight [size];
}


Airport::Airport(const Airport& a){
	this->name = a.name;
	this->num_flights = a.num_flights;
	this->cap = a.cap;

	this->f_arr = new Flight[this->cap];
	for (int i = 0 ; i < this->num_flights ; i++){
		this->f_arr[i] = a.f_arr[i];
	}

}
	
Airport& Airport::operator=(const Airport& a){
	if (this == &a) return *this; 

	if (this->f_arr != NULL) delete [] this->f_arr;

	this->name = a.name;
	this->num_flights = a.num_flights;
	this->cap = a.cap;
	
	this->f_arr = new Flight[this->cap];
	for (int i = 0 ; i < this->num_flights ; i++){
		this->f_arr[i] = a.f_arr[i];
	}
	//Intialize everything past the num_flights as NULL
	//if (this->num_flights < this->cap) for (int i = this->num_flights ; i < cap ; i ++) this->f_arr[i] = NULL; 
	return *this;

}




void Airport::populate_airport(ifstream& fin){
	//Your code goes here:
	fin >> this->name; 
	fin >> this->num_flights;
	fin >> this->cap; 
	this->f_arr = new Flight[cap];
	for(int i = 0; i < this->num_flights ; i++){
		this->f_arr[i].populate_flight(fin);
	}
	return; 
}

int Airport::search_flight_by_name(string name){
	for (int i = 0 ; i < this->num_flights ; i++){
		if (name == this->f_arr[i].get_flight_num()){
			this->f_arr[i];
			return i;
		}
	}
	return -1;
}

Flight Airport::get_flight_at(int i){
	Flight f(f_arr[i]);
	return f;
}

bool Airport::print_flight_by_name(string name){
		for (int i = 0 ; i < this->num_flights ; i++){
		if (name == this->f_arr[i].get_flight_num()){
			this->f_arr[i].print_flight();
			return true;
		}
	}
	return false;
}

void Airport::add_a_flight(Flight& p){
	//Your code goes here:
	if (!(num_flights < cap)){
		cout << endl << "Airport full" << endl;
		return;
	}
	this->f_arr[this->num_flights] = p;
	num_flights ++;
	return; 
}

Flight Airport::remove_a_flight(int idx){
	//Your code goes here:
	Flight temp = f_arr[idx];
	for (int i = idx ; i < num_flights-1 ; i++){
		f_arr[i] = f_arr[i+1];
	}
	num_flights--;
	return temp;
}

void Airport::print_airport() {
	//Your code goes here:
	cout << "Airport Name : " << this->name << " | Number of Flights : " << this->num_flights << " | Flight Capacity : " << this->cap << endl;
	for (int i = 0 ; i < num_flights ; i++){
		this->f_arr[i].print_flight();
	}
	cout << endl;
	return; 
}

int Airport::calc_dest_num(Airport* a, int size){
	int count = 0;
	for (int j = 0 ; j < size ; j++){
		for (int k = 0; k < a[j].get_num_flights() ; k++){
			if (this->name == a[j].get_f_arr()[k].get_dest())
			{
				count++;
			}

		}
	}
	return count;
}





/* ======================== 
 *  ACCESSORS AND MUTATORS
*/




void Airport::set_name(const string name){
	this->name = name;
}
string Airport::get_name() const{
	return this->name;
}

void Airport::set_num_flights(const int num_flights){
	this->num_flights = num_flights;
}
int Airport::get_num_flights() const{
	return this->num_flights;
}

void Airport::set_cap(const int cap){
	this->cap = cap;
}
int Airport::get_cap() const{
	return this->cap;
}

void Airport::set_f_arr(Flight * f_arr){
	this->f_arr = f_arr;
}
Flight* Airport::get_f_arr() const{
	return this->f_arr;
}
void Airport::set_f_idx(Flight f,const int idx){
	this->f_arr[idx] = f;

}

void Airport::increment_num_flights(){
	this->num_flights++;
}
	
void Airport::save_airport(ofstream& output_file) const{
	output_file << this->name << " "
				<< this-> num_flights << " "
				<< this->cap << " "
				<< endl;
	for (int i = 0 ; i < this->num_flights ; i++){
		this->f_arr[i].save_flight(output_file);
		output_file << endl;
		
	}
}
