#include "book.h"
#include <iostream>

using namespace std;

int main()
{
	ifstream fin; //create the file stream object
	string filename; 
	fin.open("input.txt", ios::in);
	if (!fin.is_open())
	{
		cout << "Invalid file name";
		return 1;
	}
	int size = -1;
	fin >> size; 
	cout << size << endl;

    Book *bookSet = create_books(size);
    for (int i = 0 ; i < size ; i++)
    {
       populate_one_book(bookSet, i, fin);
    }
    fin.close();


    ofstream output_file; 
    output_file.open("output.txt", ios::app);

    int UserIn = -1;
    do
    {
    cout << "Search for a book by title (0)" << endl
         << "Print all with more than 300 pages (1)" << endl
         << "Sort books by year (2)" << endl;

    cin >> UserIn; 
    } while (UserIn != 0 && UserIn != 1 && UserIn != 2);

    if (UserIn == 0)
    {
        string name;
        cout << "Enter a book title:  ";
        cin >> name;
        int indx = search_title_index(bookSet, size, name);
        if (indx != -1) save_books(bookSet[indx], output_file);
    }

    else if (UserIn == 1)
    {
        for (int i = 0 ; i < size ; i++)
        {
            if (bookSet[i].pages > 300) save_books(bookSet[i], output_file);
        }
    }
    else if (UserIn == 2)
    {
        sort_books(bookSet, size);
        for (int i = 0 ; i < size ; i++)
        {
            save_books(bookSet[i],output_file);
        }
    }

    output_file.close();
    delete_books(bookSet);
	return 0;
}