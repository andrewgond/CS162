#include <iostream>
#include "linked_list.h"

using namespace std;

void pause() {
        cout << "\n\nPress <enter> to continue...";
        cin.clear();
        cin.ignore(256, '\n');
}


int main(int argc, char const *argv[])
{
	Linked_List l;
	
	cout << "\n\nList successfully created!!\n\n";;

	cout << "**********Test 1***********\n";
	cout << "Before adding nodes...\n";
	cout << "Testing get_length()\n";
	cout << "Expected: 0\n";
	cout << "Actual  : " << l.get_length() << "\n";
	if (l.get_length() == 0)
		cout << "Test 1 PASSED\n\n";
	else
		cout << "Test 1 FAILED\n\n";
	pause();

	cout << "**********Test 2***********\n";
	cout << "Adding nodes...\n";
	cout << "Test 2.1: Testing push_front()\n";
	l.push_front(5);
	l.push_front(100);
	l.push_front(0);
	l.push_front(-8);
	l.push_front(16);
	cout << "Expected: 16 -8 0 100 5\n";
	cout << "Actual  :"; 
	l.print();
	cout << "Expected length: 5\n";
	cout << "Actual length  : " << l.get_length() << "\n";
	cout << "Test 2.1 completed.\n";
	pause();

	cout << "Removing nodes...\n";
	cout << "Test 2.2: Testing pop_front()\n";
	l.pop_front();
	l.pop_front();
	l.pop_front();
	cout << "Print list...\n";
	cout << "Expected: 100 5\n";
	cout << "Actual  :"; 
	l.print();
	cout << "Expected length: 2\n";
	cout << "Actual length  : " << l.get_length() << "\n";
	pause();

	cout << "Continue removing...\n";
	l.pop_front();
	l.pop_front();
	l.pop_front(); //no more nodes, shouldn't remove anything 
	cout << "Print list...\n";
	cout << "Expected: \n";
	cout << "Actual  :"; 
	l.print();
	cout << "Expected length: 0\n";
	cout << "Actual length  : " << l.get_length() << "\n";
	cout << "Test 2.2 completed.\n";
	pause();

	

	cout << "**********Test 3***********\n";
	cout << "Tesing clear()\n";
	//re-adding more nodes...
	l.push_front(5);
	l.push_front(100);
	l.push_front(0);
	l.push_front(-8);
	l.push_front(16);

	//then call clear()
	l.clear();
	cout << "Expected length: 0\n";
	cout << "Actual length  : " << l.get_length() << "\n";
	if (l.get_length() == 0)
		cout << "Test 3 PASSED\n";
	else
		cout << "Test 3 FAILED\n";

	cout << "Run valgrind to check memory leaks/errors\n"; 

	return 0;
}
