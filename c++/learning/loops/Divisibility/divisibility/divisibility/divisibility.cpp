// divisibility.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	int theVal = 12345678;
	int sum = 0;

	do
	{
		sum += theVal % 10;
		theVal = theVal / 10;
		cout << sum;
	} while (theVal > 0);

	cout << sum;
    
	return 0;
}

