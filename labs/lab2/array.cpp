//This is for Lab 2 Part 3: Array exercise

#include <iostream>

using namespace std;

void populate_array(int array[], int size);
void display_array(int array[], int size);
void display_stats(int array[], int size);



//function to populate the array elements
void populate_array(int array[], int size){
	//Your code here:
	for (int i = 0 ; i < size ; i++)
	{
		array[i] = rand()%100+1;
	}
	return;
}


//hint: create another function to print the statistics
void display_array(int array[], int size)
{
	cout << '[' << ' ';
	for (int i = 0 ; i < size ; i++)
	{
		cout << array[i] << ' ';
	}
	cout << ']' << endl;
}

void display_stats(int array[], int size)
{
	display_array(array, size);
	int max = array[0];
	int min = array[0];
	int total = 0;
	for (int i = 0 ; i < size ; i++)
	{
		total += array[i];
		if (array[i] > max)
		{
			max = array[i];
		}
		else if (array[i] < min)
		{
			min = array[i];
		}
	}
	cout << "Max: " << max << "  |   Min: " << min <<  "  |   Average: " << (total/size) << endl;

}

int main()
{
	srand(time(NULL));
	int arrSize, again;


	do
	{	
		cout << "Enter an integer between 5-50 ";
		cin >> arrSize; 
		cout << endl;
		while (arrSize > 50 || arrSize < 5)
		{
			cout << "Invalid input" << endl << "Enter an integer between 5-50 ";
			cin >> arrSize;
		}
		int myArr[arrSize];
		populate_array(myArr, arrSize);
		display_stats(myArr, arrSize);


		cout << "Do you want to play again? (1-yes, 0-no): ";
		cin >> again;
		cout << endl; 
		while (again != 1 && again != 0)
		{
			cout << "That's not a valid input" << endl << "Do you want to play again? (1-yes, 0-no): ";
			cin >> again ; 
			cout << endl;
		}
	}while (again == 1);

	return 0;
}