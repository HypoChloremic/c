// cheekyClasses.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "someMaths.h"
// seems extremely strange but stdafx.h must be the first include in
// a .cpp file, very strange indeed
#include <iostream>

class Matematicos {
public:
	int ooo(){
		return 12;
	}
};


int main()
{
	Matematicos proce;
	someMaths process;
	int o = process.someRandomIn();
	int p = proce.ooo();
	std::cout << o;

	return 0;
}



