// array_initializations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	int incomp_at_init[20] = { 0, 10 };
	std::cout << incomp_at_init[9];
	std::cout << "finished"; // remember to not use single quotes...
    return 0;
}

