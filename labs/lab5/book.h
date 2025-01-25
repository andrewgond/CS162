//To compile: g++ [source_code.cpp] -o [exec_file]
// replace [soure_code.cpp] with the filename, 
// replace [exec_file] with the executable file name
// i.e., g++ c++_basics.cpp -o run
//Note: if the output redirect is not given, i.e., the "-o [exec_file]" part is missing
//      then the default executable name is a.out

//To run the program, simply run the executable: ./[exec_file]
// i.e., ./a.out  (if your executable file is a.out)

#ifndef STRUCTS_H
#define STRUCTS_H 

#include <iostream> //input/output stream library
#include <string>
#include <fstream>




using namespace std; 

//definition of Book struct
struct Book
{
	string title;
    int pages;
	string author;
    int year; 
};

/**function name: create_books
   function desc: This function will create the array of books based on the number of books in the file
   param: 
   pre:
   post:
**/
Book *create_books(int);

/**function name:
   function desc.
   param.
   pre
   post:
**/
void populate_one_book(Book *, int, ifstream &);


/**function name:
   function desc.
   param.
   pre
   post:
**/
void delete_books(Book *&);

int search_title_index(Book *, int, string);

void print_books(Book);

void save_books(Book, ofstream &);

void sort_books(Book *, int);



#endif
