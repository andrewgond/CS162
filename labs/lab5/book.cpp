#include "book.h"
using namespace std;
using namespace std; 

Book* create_books(int num)
{
    Book* bookSet = new Book[num];
    return bookSet;
}



void populate_one_book(Book *bookSet, int num, ifstream &f)
{
    
    f >> bookSet[num].title;
    f >> bookSet[num].pages;
    f >> bookSet[num].author;
    f >> bookSet[num].year;

    return;
}

void delete_books(Book *& b)
{
    delete [] b;
    b = NULL;
    return;
}

int search_title_index(Book *bookSet, int size, string searchFor)
{
    int index = -1;
    for (int i = 0 ; i < size ; i++)
    {
        if (bookSet[i].title == searchFor)
        {
            return i;
        }
    }
    
    return -1;
}

void print_books(Book b)
{
    cout << "-------------" << endl
    << "Title: " << b.title << endl 
    << "Number of Pages: " << b.pages << endl 
    << "Author: " << b.author << endl 
    << "Release Year: " << b.year << endl
    << "--------------" <<endl; 
    return;
}

void save_books(Book b, ofstream &fout)
{
    fout << "-------------" << endl
    << "Title: " << b.title << endl 
    << "Number of Pages: " << b.pages << endl 
    << "Author: " << b.author << endl 
    << "Release Year: " << b.year << endl
    << "--------------" <<endl; 
    return;
}

void sort_books(Book *bookSet, int size)
{
    Book temp;
    for (int i = 0 ; i < size ; i++)
    {
        int low = bookSet[i].year;
        int lowIndx = i;
        for (int j = (i+1) ; j < size ; j++)
        {
            if (bookSet[j].year < low)
            {
                low = bookSet[j].year;
                lowIndx = j;
            }
        }
        temp = bookSet[i];
        bookSet[i] = bookSet[lowIndx];
        bookSet[lowIndx] = temp;
    }

}

