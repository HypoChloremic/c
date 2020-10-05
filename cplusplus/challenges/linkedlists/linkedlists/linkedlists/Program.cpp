#include "pch.h"
#include <iostream>

// This example code shows how you could implement the required main function
// for a Console UWP Application. You can replace all the code inside main
// with your own custom code.

// You should also change the Alias value in the AppExecutionAlias Extension
// in the package.appxmanifest to a value that you define. To edit this file
// manually, open it with the XML Editor.

int main()
{
	int input1;
	int input2;
	int throwaway;

	std::cout << "Input a number: ";
	std::cin >> input1;
	std::cout << "\nInput another number: ";
	std::cin >> input2;

	int sum = input1 + input2;
	std::cout << "\n" << input1 << " " << input2;
	std::cout << sum;
	
	std::cin >> throwaway;
	return 0;
}
