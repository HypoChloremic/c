#include <iostream>
using namespace std;

int main()
{
	int SomeArray[10];	// each int is 32-bits = 4-bytes -> in total
						// 40 bytes will have been assigned in memory
						// which is continuous. 
	int *pLocation6 = &SomeArray[6];	// so we want the address of the 
										// 6th int element in the array
	int *pLocation0 = &SomeArray[0];
	
	/*Now we wish to print the difference between these two 
	memory addresses*/
	cout << "pLocation6 = " << (int)pLocation6 << endl;
	cout << "pLocation0 = " << (int)pLocation0 << endl;
	cout << "Difference = " << pLocation6 - pLocation0 << endl;

	cout << endl; system("Pause"); return 0;
}
