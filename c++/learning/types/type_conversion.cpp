#include <iostream>

int main(){
	int a = 10;
	int b = 20;
	int c = 30;
	
	// Seemingly it is possible to dynakically convert the types of the 
	// integers to floats, and save it in d. 
	float d = (float)a + (float)b - (float)c;
	std::cout << d;
	return 0;
}
