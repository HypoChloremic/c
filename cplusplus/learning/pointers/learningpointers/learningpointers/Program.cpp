#include "pch.h"
#include <iostream>
using namespace winrt;

// This example code shows how you could implement the required main function
// for a Console UWP Application. You can replace all the code inside main
// with your own custom code.

// You should also change the Alias value in the AppExecutionAlias Extension
// in the package.appxmanifest to a value that you define. To edit this file
// manually, open it with the XML Editor.

int main()
{
	int convertee;
	// You can get parsed command-line arguments from the CRT globals.
	wprintf(L"Welcome to integer to english conversion\n");
	wprintf(L"Please enter integer: ");
	convertee = getchar();

	int  convertee2	  = convertee;
	int* ptconvertee  = &convertee;
	int* ptconvertee2 = &convertee2;
	std::cout << "\nconvertee:" << ptconvertee;
	std::cout << "\nconvertee2: " << ptconvertee2 << std::endl;

	return 0;
}
