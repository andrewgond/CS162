/* CS 162- Lab 1 - Q.2
 * Solution description: call the function foo using "reference" to see the values before and after the function
 */
 
#include <iostream>

using namespace std;

int foo(int* a, int& b, int c){
    /*Set a to double its original value*/
    *a *= 2; 
    /*Set b to half its original value*/
    b /= 2;
    /*Assign a+b to c*/
    c = (*a + b);
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 7, 8, 9 respectively*/
    int x=7, y=8, z=9;
    /*Print the values of x, y and z*/
    cout << "x is " << x << endl;
    cout << "y is " << y << endl;
    cout << "z is " << z << endl;
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
    int outFoo = foo(&x,y,z);
    /*Print the value returned by foo*/
    cout << "foo returned:  " << outFoo << endl; 
    /*Print the values of x, y and z again*/
    cout << "x is " << x << endl;
    cout << "y is " << y << endl;
    cout << "z is " << z << endl;
    
    /*Is the return value different than the value of z?  Why? */

    cout << "It's different than the value of foo because it was a pass by refrence when called" << endl;
    return 0;
}
    
    
