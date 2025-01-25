#include <iostream>

using namespace std;

/**
 *      Function: no_zero_strings(int)
 *      Description: Computes the distinct strings of length N without consecutive 0’s
 *      Parameters:
 *              int n: The length of the binary string
 *      Returns: The number of distinct strings. See the
 *              examples in the lab description for more info.
 */

int no_zero_strings(int n){
	//Your code here:

	return -1;
}


// The following is an example program that
// does some basic, limited testing of your
// no_zero_strings() implementation.
int main() {
	cout << no_zero_strings(0) << endl; // Should print 0
	cout << no_zero_strings(2) << endl; // Should print 3
	cout << no_zero_strings(3) << endl; // Should print 5
	cout << no_zero_strings(10) << endl; // Should print 144

	return 0;
}
