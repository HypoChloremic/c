// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int a = 5;
	int b = 2 + a++;
	cout << b;
    return 0;
}

