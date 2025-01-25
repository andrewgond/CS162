/* CS162- Lab 1 - Q. 1*
 * Solution description: check the properties, like value and address, of pointer
 */
 
#include <iostream>

using namespace std;


void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
     cout << "iptr: "<< *iptr << endl;
     /*Print the address pointed to by iptr*/
     cout << "iptr's address :" << iptr << endl;
     /*Print the address of iptr itself*/
     cout << "iptr the pointer address :" << &iptr << endl;
}

int main(){
    
    /*declare an integer x and initialize it with 0*/
    int x = 0;
    /*print the address of x*/
    cout << "address of x: " <<  &x << endl; 
    /*Call fooA() with the address of x*/
    fooA(&x);
    /*print the value of x*/
    cout <<  "value of x is: " << x << endl;
    return 0;
}
