#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	/*
	There are different ways a pointer can be declared: 
	int *p;

	Alternatively
	int* p;

	`int* p`  or `int *p` define a pointer variable which holds a memory address. 
	The asterisk refers to "POINTER TO..."
	
	In this case, we have a "POINTER TO int". Remember to read types from RIGHT to LEFT.
	Thus `p` is POINTING TO an integer value in the memory address 
	p holds the memory address*/

	int *p;
	cout << *p << '\n';
	/*
	p = 10;
	cout << p << '\n';
*/
	return 0;
}