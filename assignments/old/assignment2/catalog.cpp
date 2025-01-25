#include "catalog.h"

using namespace std;

//function definitions go here


/**************************************************
 * Name: create_playlists()
 * Description: This function will dynamically allocate
				an array of playlists (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Playlist array of requested size is created and return
 ***********************************************/
Playlist* create_playlists(int numPlaylists)
{
    Playlist* listOfPlaylists = new Playlist[numPlaylists];
    return listOfPlaylists;
}


/**************************************************
 * Name: populate_one_list()
 * Description: This function will fill a single playlist struct 
				with information that is read in from the file
 * Parameters:  Playlist* - pointer to the Playlist array
				int - index of the Playlist in the array to be filled 
				ifstream& - input file to get the Playlist information
 * Pre-conditions: Playlist array has been allocated; 
				 provided index is less than the array size
 * Post-conditions: a Playlist at provided index is populated
 ***********************************************/
void populate_one_list(Playlist* library, int index, ifstream & fin)
{
	//sets the variables of the playlist struct from the file
	fin >> library[index].name; 
	fin >> library[index].num_song;
	library[index].s = create_songs(library[index].num_song);
	double lengthTotal;
	for (int i = 0 ; i < library[index].num_song ; i++)	{
		//populates all the songs from the file
		populate_one_song(library[index].s , i, fin);
		lengthTotal += library[index].s[i].length;
	}
	library[index].total_len = lengthTotal;
}


/**************************************************
 * Name: create_songs()
 * Description: This function will dynamically allocate
				an array of songs (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Song array of requested size is created and return
 ***********************************************/
Song* create_songs(int num)
{
	Song* songCollec = new Song[num];
	return songCollec;
}


/**************************************************
 * Name: populate_one_song()
 * Description: This function will fill a single song struct 
				with information that is read in from the file
 * Parameters:  Song* - pointer to the Song array
				int - index of the Song in the array to be filled 
				ifstream& - input file to get the Song information
 * Pre-conditions: Song array has been allocated; 
				 provided index is less than the array size
 * Post-conditions: a Song at provided index is populated
 ***********************************************/
void populate_one_song(Song* s, int index, ifstream & fin)
{
	fin >> s[index].name;
	fin >> s[index].artist;
	fin >> s[index].year_release;
	fin >> s[index].length;
	fin >> s[index].genre;
	fin >> s[index].res;
}


/**************************************************
 * Name: delete_info()
 * Description: This function will  delete all the memory that was dynamically allocated
 * Parameters: Playlist* - the Playlist array
 * Pre-conditions: the provided Playlist array hasn't been freed yet
 * Post-conditions: the Playlist array, with all Songs inside, is freed
 ***********************************************/
void delete_info(Playlist* library, int size)
{
	for (int i = 0 ; i < size ; i++) 
	{
		delete [] library[i].s;
		library[i].s = NULL;
	}
	delete [] library;
}

/**************************************************
 * Name: fill_playlist_library()
 * Description: Uses the populate_one_list and create_playlists functions to 
 * 				fill the arrays with everything from the input file.
 * Parameters: size - size of the library playlist array 
 * 				fin - input stream 
 * Pre-conditions: a properly set up input stream and array size
 * Post-conditions: A properly filled playlist array
 ***********************************************/
Playlist* fill_playlist_library(int size, ifstream& fin){
	Playlist *library = create_playlists(size);
	for (int i = 0 ; i < size ; i++){
		populate_one_list(library, i, fin);
	}
	return library;
}


/**************************************************
 * Name: print_playlist()
 * Description: prints out the playlist in the same format as the input file
 * Parameters: p - a single playlist
 * Pre-conditions: a playlist with properly set up song array
 * Post-conditions: Printed to terminal
 ***********************************************/
void print_playlist(Playlist p, int ageCheck){
	for (int i = 0 ; i < p.num_song ; i++){
		if (!((p.s[i].res == "E" ) && ageCheck < 19)) fancy_print_song(p.s[i]);
	}
}


/**************************************************
 * Name: print_song()
 * Description: prints a song to the terminal in the same format as the input mainly for debugging
 * Parameters: s - a song to print
 * Pre-conditions: a song is properly set up
 * Post-conditions: Printed to terminal
 ***********************************************/
void print_song(Song s){
	cout << s.name << " " 
		<< s.artist << " " 
		<< s.year_release << " "
		<< s.length << " "
		<< s.genre << " " 
		<< s.res << endl;
}

/**************************************************
 * Name: fancy_print_song()
 * Description: prints a song to the terminal 
 * Parameters: s - a song to print
 * Pre-conditions: a song is properly set up
 * Post-conditions: Printed to terminal
 ***********************************************/
void fancy_print_song(Song s){
	cout << "----------" << endl 
		<< "Song name: " << s.name << endl
		<< "Song artist: " << s.artist << endl 
		<< "Release Year: " << s.year_release << endl
		<< "Song Length: " << s.length << endl
		<< "Genre: " << s.genre << endl 
		<< "Age Restriction: " << s.res << endl
		<< "----------" << endl; 
}

/**************************************************
 * Name: save_song()
 * Description: prints a song to the given file in the same format as the input
 * Parameters: s - a song to print
 * Pre-conditions: a song is properly set up
 * Post-conditions: saved to outpit file
 ***********************************************/
void save_song(Song s, ofstream& file){
	file << s.name << " " 
		<< s.artist << " " 
		<< s.year_release << " "
		<< s.length << " "
		<< s.genre << " " 
		<< s.res << endl;
}

/**************************************************
 * Name: fancy_save_song()
 * Description: prints a song to the given file in the same format as the input
 * Parameters: s - a song to print
 * Pre-conditions: a song is properly set up
 * Post-conditions: saved to outpit file
 ***********************************************/
void fancy_save_song(Song s, ofstream& file){
	file << "----------" << endl 
		<< "Song name: " << s.name << endl
		<< "Song artist: " << s.artist << endl 
		<< "Release Year: " << s.year_release << endl
		<< "Song Length: " << s.length << endl
		<< "Genre: " << s.genre << endl 
		<< " Age Restriction: " << s.res << endl
		<< "----------" << endl; 
}


/**************************************************
 * Name: run_tune_finder()
 * Description: runs the main program going into each option for a
 * Parameters: library - playlist 
 * Pre-conditions: library is already filled and set up, with size and age matching
 * Post-conditions: User is interacting with the program to show 
 ***********************************************/
void run_tune_finder(Playlist* library, int size, int age){
	while (true){ //repeats until hits the return function
		int option = prompt_main_options(); // Choses which option works best
		if (option == 1) display_all_songs(library, size, age);
		else if (option == 2) search_song_title(library, size); 
		else if (option == 3) search_song_genre(library, size, age); 
		else if (option == 4) display_total_playlist_length(library, size);
		else if (option == 5) sort_songs_by_release(library, size); 
		else if (option == 6) {
			cout << endl << "Bye!" << endl;
			return; // leaves both the loop and the function
		}
	}
}

/**************************************************
 * Name: prompt_main_options()
 * Description: Gives the user a prompt and makes sure they respond with a promper input
 * Parameters: 
 * Pre-conditions: User input is an integer
 * Post-conditions: outputted with option will be used to get into
 ***********************************************/
int prompt_main_options()
{
	int choice = 0 ;
	string prompt = "Which option would you like to choose?\n 1. Display all songs\n 2. Search for a song to play\n 3. Search Songs by Genre\n 4. Display length of all playlists\n 5. Sort songs by release year\n 6. Quit\n Your Choice: ";
	choice = prompt_for_int(prompt, 1, 6); // Error handling
	return choice;
}


/**************************************************
 * Name: prompt_display_type()
 * Description: Gives the user a prompt and makes sure they respond with a promper input
 * Parameters: n/a
 * Pre-conditions: User input is an integer
 * Post-conditions: outputted with option will be used to get into
 ***********************************************/
int prompt_display_type()
{
	int choice = 0;

	string prompt = "\n How would you like your information displayed? \n 1. Print to screen (Press 1) \n 2. Print to file (Press 2) \n Your choice: ";
	choice = prompt_for_int(prompt, 1,2);

	return choice;
	
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

/**************************************************
 * Name: establish_output_file()
 * Description: Makes the stream and sets it up to write
 * Parameters:
 * Pre-conditions: User inputs anything for a file name
 * Post-conditions: a stream is created to append anything to the file
 ***********************************************/
ofstream establish_output_file()
{
	ofstream output_file; 
	string fileName;
	cout << "Please provide desired filename: "; 
	cin >> fileName; 
    output_file.open(fileName, ios::app);
	return output_file;

}

/**************************************************
 * Name: display_all_songs()
 * Description: Loops through every playlist to print out all the songs and the playlist name
 * Parameters: library - array of playlists
 * 				size - size of the playlist array
 * 				ageCheck - to show if explicit should be shown or not
 * Pre-conditions: All paramters are properly filled
 * Post-conditions: All songs are printed to the terminal
 ***********************************************/
void display_all_songs(Playlist* library, int size, int ageCheck){
	cout << endl;
	for (int j = 0 ; j < size ; j++){
		cout << library[j].name << " ==============" << endl << "-----------" << endl;
		print_playlist(library[j], ageCheck);
		cout << endl;
	}
	cout << endl;  
}

/**************************************************
 * Name: search_song_title()
 * Description: Option for the program to run
 * Parameters: library - array of playlists
 * 				size - size of the playlist array
 * 				ageCheck - to show if explicit should be shown or not
 * Pre-conditions: 
 * Post-conditions: 
 ***********************************************/
void search_song_title(Playlist* library, int size){
	string searchFor;
	ofstream file;
	Song s;
	int displayType = prompt_display_type();
	cout << endl << "Enter a song title: ";
	cin >> searchFor; 
	for (int j = 0 ; j < size ; j++){
		for (int k = 0 ; k < library[j].num_song ; k++){
			if (searchFor == library[j].s[k].name){
				s = (library[j].s[k]);
				if (displayType == 1){
					cout << endl << "Here is your song: " << endl;
					fancy_print_song(s);
					cout << endl;
				}
				else if (displayType == 2){ // If the display type is to a file, prmopts to make that file and saves it
					file = establish_output_file();
					save_song(s, file);
					file.close();
					cout << "File has been saved" << endl << endl;
				}
				return;
			}
		}
	}
	cout << "No song of that name";
}

/**************************************************
 * Name: search_song_genre()
 * Description: Prints songs of a genre
 * Parameters: library - array of playlists
 * 				size - size of the playlist array
 * 				ageCheck - to show if explicit should be shown or not
 * Pre-conditions: paramters are filled out
 * Post-conditions: Songs of a certain genre are printed/written to a file
 * 
 ***********************************************/
void search_song_genre(Playlist* library, int size, int ageCheck){
	string searchForGenre;
	ofstream file;
	int displayType = prompt_display_type();
	if (displayType == 2) file = establish_output_file();
	cout << "Enter genre: ";
	cin >> searchForGenre; 
	for (int j = 0 ; j < size ; j++){
		for (int k = 0 ; k < library[j].num_song ; k++){
			// If statement so that only songs that are the right genreand aren't age restricted are shown to those under 19
			if ((searchForGenre == library[j].s[k].genre) && !((library[j].s[k].res == "E" ) && ageCheck < 19)){
				if (displayType == 1) fancy_print_song(library[j].s[k]);
				else if (displayType == 2) save_song(library[j].s[k], file);
			}
		}
	}
	if (displayType == 2) cout << "File has been saved." << endl;
	cout << endl;
	file.close();
	return;
}

/**************************************************
 * Name: display_total_playlist_length()
 * Description: Computes the length of all playlists and combines them for total length
 * Parameters: library - array of playlists
 * 				size - size of the playlist array
 * Pre-conditions: library and size are filled
 * Post-conditions: Length of every song in the library is printed to the terminal 
 ***********************************************/
void display_total_playlist_length(Playlist* library, int size)
{
	double totalLen = 0;
	cout << endl << "---------------" << endl; 
	for (int j = 0 ; j < size ; j++){
		double playlistLen = 0 ;
		for (int k = 0 ; k < library[j].num_song ; k++){
			playlistLen += library[j].s[k].length;
			totalLen += library[j].s[k].length;
		}
		cout << library[j].name << " Playlist is " << playlistLen << " minutes long \n";
	}
	cout << "Total length of all playlists is:   " << totalLen << " minutes long" << endl << "---------------" << endl << endl ; 
}

/**************************************************
 * Name: sort_songs_by_release() 
 * Description: Extra credit, sorts every song from the palylist 
 * Parameters: library - playlist array
 * 				size - size of playlist array
 * Pre-conditions: library and size are filled
 * Post-conditions: All songs are printed to the terminal in order from release date
 ***********************************************/
void sort_songs_by_release(Playlist* library, int size){
	int numSongs = 0;
	for (int i = 0 ; i < size ; i++) numSongs += library[i].num_song; 
	Song* sortedSongs = new Song[numSongs];
	int songIndex = 0;
	for (int j = 0 ; j < size ; j++){
		for (int k = 0 ; k < library[j].num_song ; k++){
			sortedSongs[songIndex] = library[j].s[k];
			songIndex++;
		}
	}
	sortAlgorithim(sortedSongs, numSongs);
	delete [] sortedSongs;
	sortedSongs = NULL;
}


/**************************************************
 * Name: sortAlgorithim
 * Description: Algorithim to actually sort by year 
 * Parameters: sortedSongs - n
 * 				numSongs - size of the array
 * Pre-conditions: library and size are filled
 * Post-conditions: songs are now in order
 ***********************************************/
void sortAlgorithim(Song* sortedSongs, int numSongs)
{
	Song temp;
    for (int i = 0 ; i < numSongs ; i++){ //loops through the array from left to right
        int low = sortedSongs[i].year_release;
        int lowIndx = i;
        for (int j = (i+1) ; j < numSongs ; j++){ //Finds the lowest year to the right of the value
            if (sortedSongs[j].year_release < low){
                low = sortedSongs[j].year_release;
                lowIndx = j;
            }
        } // replaces the current song with the lowest length song
        temp = sortedSongs[i];
        sortedSongs[i] = sortedSongs[lowIndx];
        sortedSongs[lowIndx] = temp;
		print_song(sortedSongs[i]);
    }
}