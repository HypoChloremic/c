#include "pch.h"


// This example code shows how you could implement the required main function
// for a Console UWP Application. You can replace all the code inside main
// with your own custom code.

// You should also change the Alias value in the AppExecutionAlias Extension
// in the package.appxmanifest to a value that you define. To edit this file
// manually, open it with the XML Editor.
int someFunction(int, int);


int main()
{
    
	int x = 10;
	int y = 12;
	int returnedval = someFunction(x, y);
	printf("Hello");
    wprintf(L"%d", returnedval);
	//cout << returnedval;
    getchar();
}


// Ajt, so it seems that we can easily wrinf integers, it is
// just that I cannot seem to be printing, or outputting doubles
// On the other hand, the src demonstrates the ability to be passing values
// to methods relatively easily. 
int someFunction(int x, int y) {
	return x + y;
}