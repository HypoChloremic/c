// struct_basics.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "A.h"
#include <iostream>

int main()
{
	/*In the header file we created a struct object
	with a member function called memberfunction()*/
	A a;
	std::cout << a.memberfunction(10) << std::endl;
	std::cout << "Finished" << std::endl;
    return 0;
}

