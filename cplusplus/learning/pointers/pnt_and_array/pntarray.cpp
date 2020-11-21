#include <iostream>
using namespace std;


int main()
{
    // will assign 40-bytes of continuous memory
	int SomeArray[10] = { 3, 6, 9, 12, 15, 18, 21, 24, 27, 30 };	

    // arrays in c and c++ are just pointers themselves, 
    // we will not need the address of operator, &:
	int *pLocation0 = SomeArray;

    // lets display the contents of the array
    for (int i = 0; i < 10; i++)
    {
        cout << SomeArray[i] << endl;
    }
    
    // another way of displaying this:
    for(int i = 0; i<10; i++)
    {
        // we know that we are storing the addresses at each location
        // thus we can use the * operator to get the value at the address
        cout << "address: " << SomeArray + i; // this will print each hex adress, with 4 byte spaces
        cout << " == " << *(SomeArray + i) << endl;
    }

	cout << endl; system("Pause"); return 0;
}