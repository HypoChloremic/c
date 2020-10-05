#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	int myArray[10];
	for (int i = 0; i < 10; ++i)
	{
		myArray[i] = i+10;
	}

	cout << myArray[1] << " " << myArray[4];
	return 0;
}