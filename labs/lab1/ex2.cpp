#include <iostream>

using namespace std;

void function(int num, int ctr, int &r) {
  int i;
  for(i = 2;i <= num/2; i++){
    if(num % i==0){
      ctr++; 
      break; //exits loop if there is any factor in half the given number that has a nice factor
    }
  }
  if(ctr == 0 && num != 1) //checks if the number
    r = 1; //updates the r outside the function
  else
    r = 0; //updates the r outside the function
}

int main(){

  int num, ctr = 0, r = -1;
  cout << "Input a number: ";
  cin >> num;
  
  function(num, ctr, r);
  cout << r << endl;; // Checks if the number is prime and outputs 1 if it is

  return 0;
}