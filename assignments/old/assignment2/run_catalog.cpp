/******************************************************
** Program: run_catalog.cpp
** Author: Andrew Gondoputro
** Date: 2/10/2024
** Description: Tune finder program
** Input: User inputs / txt files
** Output: txt files and terminal outputs
******************************************************/

#include "catalog.h"

using namespace std;

int main()
{
	//Setting up the inputs
	ifstream inputStream; //create the file stream object
	string filename = "songs_playlist.txt"; 
	
	int age = 0;
	cout << "Enter input file: ";
	cin >> filename;
	inputStream.open(filename, ios::in);
	if (!inputStream.is_open()){
		cout << "File does not exist \n";
		return 1;
		}
	age = prompt_for_int("Enter your age: ", 1, 99999);
	int size = -1; 
	inputStream >> size; 
	Playlist *playlistLibrary = fill_playlist_library(size, inputStream);
	inputStream.close();

	run_tune_finder(playlistLibrary, size, age);

	delete_info(playlistLibrary, size);	
	return 0;
}