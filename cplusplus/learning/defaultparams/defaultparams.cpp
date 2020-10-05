#include <iostream>

using namespace std;

void printthis(const char* x, const char* y){
	cout << x << y;
}	

int main(int argc, char const *argv[])
{
	/*Cpp är inavlat, parameter name kan inte användas inne i callback functions*/

	printthis("Hello", " there\n");
	return 0;
}

