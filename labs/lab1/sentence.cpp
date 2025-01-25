#include <iostream>
#include <string>

using namespace std;

void get_sentence(string &s){
	cout << "Enter a sentence: ";
	getline(cin, s);
}
/* 
What is indeed passed into the function if an ampersand (&) is added in front of the parameter? 
 		If an & is added in front of a paramater then it becomes a pass by refrence rather that just a 
		pass by value. This means rather than just a copy of the paramater it actually holds the same place in
		memory.
*/


/*
Can we change the value of the string inside the function if we change the function prototype to:
void get_sentence(string &sentence);
		We can change it to &sentence then it would properly print out the output, because its a pass by refrence.

*/

/*
What is the difference between pass by value vs. pass by reference
		The difference between pass by value vs pass by reference is that the pass by refrence 
		lets you manipulate a variable because it replaces it value in the memory rather than just a 
		copy of the value/
*/	
int main()
{
	string sentence;

	get_sentence(sentence);
	cout << sentence << endl;

	return 0;
}