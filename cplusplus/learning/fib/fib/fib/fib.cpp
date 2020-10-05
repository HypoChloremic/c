// fib.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;


int fib(int input_value){
	int k = input_value;
	int a1 = 0;
	int a2 = 1;
	int o;

	for (int i = 1; i < k; i++)
	{
		o = a2;
		a2 = a2 + a1;
		a1 = o;
	}
	
	return a2;
}

int main()
{

	int fib_result = fib(70);
	ofstream result_file; 
	result_file.open("fib_result.txt");
	result_file << fib_result;
	result_file.close();
	return 0;
}

