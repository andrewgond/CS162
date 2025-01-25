#include <iostream>

using namespace std;

// take an int argument, represent the size of the array,
// and return the address of the array
int* create_array1(int size);

// take a reference to an int pointer to allocate the array,
// and an int argument, represent the size of the array
void create_array2(int *& array, int size);


// take the address of an int pointer, dereference it to allocate,
// and an int argument, represent the size of the array
void create_array3 (int ** array, int size);



int main()
{
	//Your code here:
	int size;
    cout << "enter size: "; 
    cin >> size;

    int* arr1 = create_array1(size);
    int* arr2; 
    create_array2(arr2, size);

    int* arr3;
    create_array3(&arr3, size);

    delete [] arr1;
    arr1 = NULL;
    delete [] arr2;
    arr2 = NULL;
    delete [] arr3;
    arr2 = NULL;


	return 0;
}

int* create_array1(int size)
{
    int* temp = new int[size];
    return temp;
}

void create_array2(int *& array, int size)
{
    array = new int [size];
}

void create_array3 (int ** array, int size)
{
    *array = new int [size];
}