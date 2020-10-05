#include "pch.h"
#include <iostream>
using namespace std;


// You should also change the Alias value in the AppExecutionAlias Extension
// in the package.appxmanifest to a value that you define. To edit this file
// manually, open it with the XML Editor.

int main()
{
	cout << "Welcome to the temperature converter\n";
	int lowerlimit;
	int higherlimit;
	int stepsize;
	float celsius;
	float fahrenh;
	
	cout << "Enter lower limit in centigrade: ";
	cin  >> lowerlimit;
	cout << "Enter higherlimit in centrigrade: ";
	cin  >> higherlimit;
	cout << "Enter the stepsize: ";
	cin  >> stepsize;

	cout << "	Celsius         Fahrenheit\n-----------------\n";

	for (size_t i = lowerlimit; i <= higherlimit; i+=stepsize)
	{
		celsius = i;
		fahrenh = 33.8*celsius;
		cout << celsius << "         " << fahrenh <<"\n";
		
	}
	int throwaway;
	cin >> throwaway;
	return 0;
}
