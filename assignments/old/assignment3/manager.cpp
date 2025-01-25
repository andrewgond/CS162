#include "manager.h"

using namespace std;


Manager::Manager(){
	
}

Manager::~Manager() {
	if (this->a_arr != NULL){
	delete [] this->a_arr;
	this->a_arr = NULL;
}
}

void Manager::populate(ifstream& fin) {
	//Your code goes here:
	fin >> this->num_airports;
	this->a_arr = new Airport[this->num_airports]; //initalizes the array of airports
	for (int i = 0 ; i < this->num_airports ; i++ ){
		this->a_arr[i].populate_airport(fin);
	}
	return; 
}

int Manager::init(){
	ifstream fin("airport.txt");
	//Error opening file?:
	if (!fin.is_open()){
		cout << "File does not exist \n";
		return 0;
		}
	//Your code goes here:
	Manager::populate(fin);
	fin.close();

	return 1;
}

void Manager::print_menu(){
	cout << endl;
	cout << "1. View all Airports & Flights info" << endl;
	cout << "2. Check flight info" << endl;
	cout << "3. Add a new flight" << endl;
	cout << "4. Cancel a flight" << endl;
	cout << "5. Take off a flight" << endl;
	cout << "6. Print airport stats" << endl;
	cout << "7. Simulate all flights " << endl;
	cout << "8. Quit" << endl;

	cout << "Your choice: ";
}

int Manager::get_menu_choice() {
	int choice = 0;
	//Manager::print_menu();
	//cin >> choice;
	
	//Don't forget error handling!!!
	choice = Manager::prompt_for_choice(1,8);

	return choice;
}

void Manager::print_all(){
	//Your code goes here:
	cout << " -----------------" << endl;
	for (int i = 0 ; i < num_airports ; i++)
	{
		this->a_arr[i].print_airport();
	}
	cout << " -----------------" << endl;
	return; 
}

void Manager::check_flight_control() {
	//Your code goes here:
	string flight_number;
	cout << "Enter your flight number: " ;
	cin >> flight_number;
	cout << endl;
	for (int i = 0 ; i < this->num_airports ; i++)
	{
		if (this->a_arr[i].print_flight_by_name(flight_number)) return;
	}
	cout << "Flight not found " << endl ;
	return; 
}

void Manager::add_flight_control() {
	//Your code goes here:
	string airport_name; 
	cout << "Enter flight's current airport : ";
	cin >> airport_name; 
	cout << endl; 
	for (int i = 0 ; i < this->num_airports ; i ++){
		if (this->a_arr[i].get_name() == airport_name){ //Testing to see if the airport chose is full
			if (this->a_arr[i].get_cap() <= this->a_arr[i].get_num_flights()){
				cout << "Error -- Airport Full" << endl ;
				return;
			}
			else{
				Flight f = prompt_for_new_flight(airport_name);
				this->a_arr[i].add_a_flight(f);
				return;
			}
		}
	}
	cout << "Airport not found " << endl;


	return; 
}

void Manager::cancel_flight_control() {
	//Your code goes here:
	string flight_name; 
	cout << "Enter flight number : ";
	cin >> flight_name;

	for (int i = 0 ; i < this->num_airports ; i++)
	{
		if (this->a_arr[i].search_flight_by_name(flight_name) != -1)
		{
			this->a_arr[i].remove_a_flight(this->a_arr[i].search_flight_by_name(flight_name));
			cout << "Flight " << flight_name << " has been removed" << endl;
			return;
		}
	}
	cout << "Flight not found " << endl; 

	return;
}

void Manager::take_off_control() {
	//Your code goes here:
	string flight_name; 
	cout << "Enter flight number : ";
	cin >> flight_name;

	for (int i = 0 ; i < this->num_airports ; i++)
	{
		int flight_idx = this->a_arr[i].search_flight_by_name(flight_name);
		if (flight_idx != -1) // means its been found 
		{
			Flight f = this->a_arr[i].get_flight_at(flight_idx);
			for (int a = 0 ; a < this->num_airports ; a++){
				if (f.get_dest() == this->a_arr[a].get_name()){
					if (this->a_arr[a].get_num_flights() == this->a_arr[a].get_cap()){
						cout << endl << "ERROR - Destination of flight is full" << endl;
						return;
					}
					this->a_arr[i].remove_a_flight(flight_idx);
					f.set_curr_loc(this->a_arr[a].get_name());
					this->a_arr[a].add_a_flight(f);
					cout << endl << "Flight " << f.get_flight_num() << " has taken off properly" << endl;
					return;
				}
			}
			return;
		}
	}
	cout << "Flight not found " << endl; 

	return; 
}

void Manager::stats_control() {
	//Your code goes here:
	cout << " -----------------" << endl;
	for (int i = 0 ; i < num_airports ; i++)
	{
		cout << "Airport Name: " << this->a_arr[i].get_name() << endl
			<< "Capacity: " << this->a_arr[i].get_cap() << endl 
			<< "Listed as destination: " << this->a_arr[i].calc_dest_num(this->a_arr, this->num_airports) << endl;
	}
	cout << " -----------------" << endl;
	return; 

}

void Manager::simulate_all_control() {
	if (check_over_cap(this->a_arr, this->num_airports)){
		cout << "ERROR ----  more flights listed as their destination than its capacity allows" << endl;
		return; 
	}
	int total_flights = (calc_total_flights(this->a_arr, this->num_airports));
	Flight* f = just_flights(total_flights);
	for (int i = 0 ; i < total_flights ; i++){
		for (int j = 0 ; j < this->num_airports ; j++){
			if (this->a_arr[j].get_name() == f[i].get_dest()){
				cout << "Flight " << f[i].get_flight_num() << " is moved from "
					<< f[i].get_curr_loc() << " to " << f[i].get_dest() << endl;
				f[i].set_curr_loc(f[i].get_dest());
				this->a_arr[j].set_f_idx(f[i], this->a_arr[j].get_num_flights());
				this->a_arr[j].increment_num_flights();
			}
		}
	}
	delete [] f;
	f = NULL; 
	return;
}

Flight* Manager::just_flights(int total_flights){
	Flight* f = new Flight[total_flights];
	int c = 0; 
	for (int j = 0 ; j < this-> num_airports ; j++){
		for (int k = 0 ; k < this->a_arr[j].get_num_flights() ; k++){
			f[c] = this->a_arr[j].get_flight_at(k);
			this->a_arr[j].get_f_arr()[k] = Flight();
			c++;
		}
		this->a_arr[j].set_num_flights(0);
	}
	return f;
}

bool Manager::check_over_cap(Airport* a, int size){
	bool full = false; 
	for (int i = 0 ; i < size ; i++){
		if (a[i].get_cap() < a[i].calc_dest_num(a, size)) full = true;
	}
	//cout << "full? : " << full;
	return full;
}

int Manager::calc_total_flights(Airport* a, int size){
	int count = 0; 
	for (int i = 0 ; i < size ; i++){
		count += a[i].get_num_flights();
	}
	return count;
}

void Manager::run() {
	cout << endl;
	cout << "Welcome to Flight Manager!!" << endl;
	if (Manager::init() != 1)
		return;

	int choice = -1;
	while (choice != 8)
	{
		choice = Manager::get_menu_choice();

		//print all
		if (choice == 1) 
			Manager::print_all();

		//flight info
		else if (choice == 2){
			Manager::check_flight_control();
		}
		//add a new flight
		else if (choice == 3) {
			Manager::add_flight_control();
		}
		//cancel a flight
		else if (choice == 4) {
			Manager::cancel_flight_control();
		}
		//take off a flight
		if (choice == 5){
			Manager::take_off_control();
		}
		//airport stats
		else if (choice == 6) {
			Manager::stats_control();
		}
		//extra credit
		else if (choice == 7) {
			Manager::simulate_all_control();
		}
	}
	Manager::update_file();
	cout << "Bye!" << endl << endl;

	return;
}


Flight Manager::prompt_for_new_flight(string curr_loc){

	string flight_num, dest;			
	int num_pilots;			

	cout << "Enter Flight number: " ; 
	cin >> flight_num;
	bool dest_exists = false; 
	do {
	cout << endl << "Enter destination: "; 
	cin >> dest; 
	for (int i = 0 ; i < this->num_airports ; i++){
		if (dest == this->a_arr[i].get_name())
			dest_exists = true;
	} 
	cout << endl;
	if (curr_loc == dest) dest_exists = false;
	if (!dest_exists) cout << "Invalid destination " << endl; 

	} while (!dest_exists);

	num_pilots = prompt_for_int("Enter number of pilots: ", 0, 10);
	string* pilots = new string[num_pilots]; 
	for (int i = 1 ; i <= num_pilots ; i++){
		cout << "Enter pilot " << i << "'s name: ";
		cin >> pilots[i-1];
	}
	Flight f(flight_num, curr_loc, dest, num_pilots, pilots);
	delete [] pilots;  
	return f;
}


int Manager::prompt_for_choice(int min, int max)
{
	int output; 
	do {
		//Checks if the input stream previously failed or not and resets it
		if (cin.fail()){
			cin.clear(); 
			cin.ignore(1000000,'\n');
		}
		Manager::print_menu();
		cin >> output; 
		if (output < min || output > max || cin.fail()) cout << "Invalid Input" << endl; //States error
	} while (output < min || output > max || cin.fail());
	return output;
}

int Manager::prompt_for_int(string request , int min, int max)
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

void Manager::update_file()
{
	ofstream output_file; 
	output_file.open("airport.txt", ios::trunc);
	output_file << (this->num_airports) << endl;
	for (int a = 0 ; a < this->num_airports ; a++){
		this->a_arr[a].save_airport(output_file);
	}
	output_file.close();
}

