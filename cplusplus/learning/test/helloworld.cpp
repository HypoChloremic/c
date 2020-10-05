#include <iostream>
using namespace std;

int something(){
	int k = 10;
	int z = 20;
	return k+z;
}

int main(int argc, char const *argv[])
{
	int meh = something();
	cout << "Hello World "<< meh;
	return 0;
}