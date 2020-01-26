// Comparing performance with a python script using a fib sequences
// (c) 2017 Ali Rassolie
 
#include <iostream>
using namespace std;

int fib(int input){


	long long int a,a2, temp;

	a  = 0;
	a2 = 1;
	for (int i = 0; i < input; i++)
	{
		temp = a2;
		a2 = a2 + a;
		a = temp;
		cout << a2 << "\n";
	}
	return a2;
}

int fibSlow(int n){
	switch(n){
		case 0:
			return 0;
		case 1:
			return 1;
		default:
			return fibSlow(n-1)+fibSlow(n-2);
	}


}

int main()
{
	int *inputNumber = new int;
	cin >> *inputNumber;
	cout << fibSlow(*inputNumber);
	return 0;
}