#include <iostream>

using namespace std;

struct Node
{
	int val;
	Node* next;
};


int main()
{
	Node* head = new Node;
	Node* current = head;
	int size = 3;

	// Task 1: What does this code do?
	// Trace through the code and draw the picture out
	for (int i = 0; i < size; ++i){
		current->val = i+1;
		if (i == size-1)
			current->next = nullptr;
		else{
			current->next = new Node;
			current = current->next;
		}
	}

	//Task 2: print the list out
    current = head; 
    for (int i = 0 ; i < size ; i++){
        cout << current->val<< endl;
        current = current->next;
    }

	//Task 3: Free the memory allocated by the list

	return 0;
}