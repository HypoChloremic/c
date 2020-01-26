#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main()
{
	int *pointer_to_string = new int;
	*pointer_to_string = 10;
	string s[10];
	for (int i = 0; i < 10; ++i)
	{
		s[i] = "hello";
		cout << s[i] << "\n" << i;
	}


	return 0;
}
