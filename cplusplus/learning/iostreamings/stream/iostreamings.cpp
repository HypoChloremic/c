// iostreamings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	char ch;
	cout << "Hello"<<endl;
	cin.get(ch);
	cout << ch;
	cout << cin.peek();
	cin.putback(ch);
	cout << ch;

	return 0;
}