#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//a struct to hold info of a Playlist
struct Playlist {
	string name;        //name of the playlist, one word
	int num_song;       //number of songs in the playlist
	struct Song *s;     //an array that holds all songs in the playlist
	float total_len;    //total length of the playlist
};

//a struct to hold info of a Song
struct Song {
	string name;		//name of the song, one word
	string artist;		//name of the artist, one word
	int year_release;	//the year of release
	float length;		//length of the song
	string genre;		//genre of the song, one word
	string res;			//"E" or "none" for restriction level
};


/**************************************************
 * Name: create_playlists()
 * Description: This function will dynamically allocate
				an array of playlists (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Playlist array of requested size is created and return
 ***********************************************/
Playlist* create_playlists(int);


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
void populate_one_list(Playlist*, int, ifstream &); 


/**************************************************
 * Name: create_songs()
 * Description: This function will dynamically allocate
				an array of songs (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Song array of requested size is created and return
 ***********************************************/
Song* create_songs(int);


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
void populate_one_song(Song*, int, ifstream &); 


/**************************************************
 * Name: delete_info()
 * Description: This function will  delete all the memory that was dynamically allocated
 * Parameters: Playlist* - the Playlist array
 * Pre-conditions: the provided Playlist array hasn't been freed yet
 * Post-conditions: the Playlist array, with all Songs inside, is freed
 ***********************************************/
void delete_info(Playlist*, int);



/**************************************************
 * Name: fill_playlist_library()
 * Description: Uses the populate_one_list and create_playlists functions to 
 * 				fill the arrays with everything from the input file.
 * Parameters: size - size of the library playlist array 
 * 				fin - input stream 
 * Pre-conditions: a properly set up input stream and array size
 * Post-conditions: A properly filled playlist array
 ***********************************************/
Playlist* fill_playlist_library(int size, ifstream& fin);

/**************************************************
 * Name: print_playlist()
 * Description: prints out the playlist in the same format as the input file
 * Parameters: p - a single playlist
 * Pre-conditions: a playlist with properly set up song array
 * Post-conditions: Printed to terminal
 ***********************************************/
void print_playlist(Playlist , int);

void save_playlist(Playlist , int);

/**************************************************
 * Name: print_song()
 * Description: prints a song to the terminal in the same format as the input mainly for debugging
 * Parameters: s - a song to print
 * Pre-conditions: a song is properly set up
 * Post-conditions: Printed to terminal
 ***********************************************/
void print_song(Song );

/**************************************************
 * Name: fancy_print_song()
 * Description: prints a song to the terminal 
 * Parameters: s - a song to print
 * Pre-conditions: a song is properly set up
 * Post-conditions: Printed to terminal
 ***********************************************/
void fancy_print_song(Song);

/**************************************************
 * Name: save_song()
 * Description: prints a song to the given file in the same format as the input
 * Parameters: s - a song to print
 * Pre-conditions: a song is properly set up
 * Post-conditions: saved to outpit file
 ***********************************************/
void save_song(Song, ofstream&);

/**************************************************
 * Name: fancy_save_song()
 * Description: prints a song to the given file in the same format as the input
 * Parameters: s - a song to print
 * Pre-conditions: a song is properly set up
 * Post-conditions: saved to outpit file
 ***********************************************/
void fancy_save_song(Song , ofstream&);

/**************************************************
 * Name: run_tune_finder()
 * Description: runs the main program going into each option for a
 * Parameters: library - playlist 
 * 				size - 
 * 				age - 
 * Pre-conditions: library is already filled and set up, with size and age matching
 * Post-conditions: User is interacting with the program to show 
 ***********************************************/
void run_tune_finder(Playlist*, int, int);

/**************************************************
 * Name: prompt_main_options()
 * Description: Gives the user a prompt and makes sure they respond with a promper input
 * Parameters: 
 * Pre-conditions: User input is an integer
 * Post-conditions: outputted with option will be used to get into
 ***********************************************/
int prompt_main_options();

/**************************************************
 * Name: display_all_songs()
 * Description: Loops through every playlist to print out all the songs and the playlist name
 * Parameters: library - array of playlists
 * 				size - size of the playlist array
 * 				ageCheck - to show if explicit should be shown or not
 * Pre-conditions: All paramters are properly filled
 * Post-conditions: All songs are printed to the terminal
 ***********************************************/
void display_all_songs(Playlist*, int, int);

/**************************************************
 * Name: search_song_title()
 * Description: Option for the program to run
 * Parameters: library - array of playlists
 * 				size - size of the playlist array
 * 				ageCheck - to show if explicit should be shown or not
 * Pre-conditions: 
 * Post-conditions: 
 ***********************************************/
void search_song_title(Playlist*, int);

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
void search_song_genre(Playlist*, int, int);

/**************************************************
 * Name: display_total_playlist_length()
 * Description: Computes the length of all playlists and combines them for total length
 * Parameters: library - array of playlists
 * 				size - size of the playlist array
 * Pre-conditions: library and size are filled
 * Post-conditions: Length of every song in the library is printed to the terminal 
 ***********************************************/
void display_total_playlist_length(Playlist*, int);

/**************************************************
 * Name: sort_songs_by_release() 
 * Description: Extra credit, sorts every song from the palylist 
 * Parameters: library - playlist array
 * 				size - size of playlist array
 * Pre-conditions: library and size are filled
 * Post-conditions: All songs are printed to the terminal in order from release date
 ***********************************************/
void sort_songs_by_release(Playlist*, int);

/**************************************************
 * Name: prompt_display_type()
 * Description: Gives the user a prompt and makes sure they respond with a promper input
 * Parameters: n/a
 * Pre-conditions: User input is an integer
 * Post-conditions: outputted with option will be used to get into
 ***********************************************/
int prompt_display_type();

/**************************************************
 * Name: establish_output_file()
 * Description: Makes the stream and sets it up to write
 * Parameters:
 * Pre-conditions: User inputs anything for a file name
 * Post-conditions: a stream is created to append anything to the file
 ***********************************************/
ofstream establish_output_file();

/**************************************************
 * Name: sortAlgorithim
 * Description: Algorithim to actually sort by year 
 * Parameters: sortedSongs - n
 * 				numSongs - size of the array
 * Pre-conditions: library and size are filled
 * Post-conditions: songs are now in order
 ***********************************************/
void sortAlgorithim(Song*, int);

/**************************************************
 * Name: prompt_for_int()
 * Description: Works as error handling and prompting
 * Parameters: String with prompt/request, and min/max domain for int
 * Pre-conditions: User input is an integer
 * Post-conditions: an int that matches the requirements
 ***********************************************/
int prompt_for_int(string, int, int);


