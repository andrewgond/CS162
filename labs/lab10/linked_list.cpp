#include "linked_list.h"

int Linked_List::get_length() {
	// note: there is no set_length(unsigned int) (the reasoning should be intuitive)
	// Your code goes here:
	return length;
}

void Linked_List::print(){
	// output a list of all integers contained within the list
	// Your code goes here:
	
	
	if (this->head == nullptr) {
		cout << "\n";
		return;
	}
	Node* out = this->head;
	while (out->next != nullptr){
		cout << out->val << " ";
		out = out->next;
	}
	cout << out->val << endl;
	return;
}

void Linked_List::clear(){
	// delete the entire list (remove all nodes and reset length to 0)
	// Your code goes here:
	while (head != NULL){
		Node* temp = head; 
		head = head->next;
		temp->next = NULL;
		length --;
		delete temp;
	}
	return;
}

void Linked_List::push_front(int val){
	// insert a new value at the front of the list 
	// Your code goes here:
	Node* temp = head; 
	head = new Node(val, temp);
	length ++;
	return;
}

void Linked_List::pop_front(){
	// remove the node at the front of the list
	// Your code goes here:
	if (!(head == nullptr)){
		Node* temp = head; 
		head = head->next;
		temp->next = NULL;
		length --;
		delete temp;
	}

}
