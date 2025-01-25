#include <iostream>

using namespace std;

struct multdiv_entry {
	int mult;
	float div;
};


//function prototypes
multdiv_entry** create_table(int row, int col);
void print_table(multdiv_entry** tables, int row, int col);
void delete_table(multdiv_entry** tables, int row);


int main()
{
	//Your code here:
	int rows; 
	int cols;
	int playAgain = 0;
	do
	{
	cout << "How many Rows?   ";
	cin >> rows;
	cout << "How many Cols?   ";
	cin >> cols; 
	multdiv_entry** myArray; 
	myArray = create_table(rows, cols);
	print_table(myArray, rows, cols);
	delete_table(myArray, rows);
	cout << "Would you like to see a different size matrix? (0 - no, 1 - yes)";
	cin >> playAgain;
	} while (playAgain == 1);


	return 0;
}

multdiv_entry** create_table(int row, int col)
{
	multdiv_entry** outArray = new multdiv_entry*[row]; 
	for (int i = 0 ; i < row ; i++)
	{
		outArray[i] = new multdiv_entry[col];
	}
	for (int j = 0 ; j < row ; j++)
	{
		for (int k = 0 ; k < col ; k++)
		{
			outArray[j][k].mult = ((k+1)*(j+1));
			outArray[j][k].div = ((double)(j+1)/(k+1));
		}
	}
	return outArray;

}


void print_table(multdiv_entry** tables, int row, int col)
{
	cout << "Multiplication Table: " << endl;
	for (int j = 0 ; j < row ; j++)
	{
		for (int k = 0 ; k < col ; k++)
		{
			cout << tables[j][k].mult << "\t";
		}
		cout << endl; 
	}

	cout << "Division Table: " << endl;
	for (int j = 0 ; j < row ; j++)
	{
		for (int k = 0 ; k < col ; k++)
		{
			cout << tables[j][k].div << "\t";
		}
		cout << endl; 
	}
	return;
}

void delete_table(multdiv_entry** tables, int row)
{
	for (int i = 0; i < row ; i++)
	{
		delete [] tables[i];
		tables[i] = NULL;
	}
	delete [] tables;
	tables = NULL; 
	return;
	
}
