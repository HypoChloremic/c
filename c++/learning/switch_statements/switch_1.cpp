// Playing around with switch sttements

#include <iostream>
#include <string>
using namespace std;

int sw(int i)
{
	switch(i){
		case int:
			cout << "i is an int";

		// it seems that switch does not like strings, or any other types
		// than integral. Ive now read that there are options where
		// you create an eval func for the string which returns true or not 
		// for its type
		case std::string:
			cout << "i is a string";
		default:
			cout << "default output";
	}
	return 0;
}

int ev(int i, str *s){


}

int main(int argc, char const *argv[])
{

	int *i = new int;
	string s = new string;
	
	*i = NULL
	*s = NULL

	second_switch(i, s);
	
	if (*i != NULL)
	{
		cout << "we got an integer"
	}
	if (*s != NULL)
	{
		cout << "we got a string"
	}

	return 0;
}