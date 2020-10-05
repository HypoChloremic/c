#include "pch.h"

// namespace is used because there are methods and functions
// that are NOT defined under the GLOBAL namespace, which in 
// turn to be accessed one uses the :: operator, for instance
// std::cout and std::cin etc. 
//using namespace std;

int main()
{
	int convertee;
    // You can get parsed command-line arguments from the CRT globals.
    wprintf(L"Welcome to integer to english conversion\n");
	wprintf(L"Please enter integer: ");
	convertee = getchar();

	int convertee2 = convertee;
	int* ptconvertee = &convertee;
	int* ptconvertee2 = &convertee2;
	std::cout << "\nconvertee:"   << ptconvertee;
	std::cout << "\nconvertee2: " << ptconvertee2 << std::endl;




	// so the sign in unsigned and signed is talking about
	// the presence or absence of a + or a minus sign in
	// front of the number in question. Because we are working
	// with prespecified ranges of numbers, i.e. how much
	// we can io, in terms of bits, such as 16,32, and 64 
	// bit systems respectively, we can economize around these
	// by choosing to include the negative range, thus moving
	// the interval to include negative numbers, or solely
	// have the positive range, and move the interval to include 
	// those only.
	unsigned int number_of_digits = 0;
	unsigned int base = 10;


	// aight a thing we can learn here is something called template parameters:
	// template parameters are used because there may be a template (ie type(object))
	// that takes parameters in order to be defined. In order to provide these 
	// parameters we use the <> operators. 
	std::map<int, std::string> dic = {
	{1, "ten"},
	{2, "hundred"},
	{3, "thousand"},
	{4, "million"},
	{5, "billion"}
	};

	// Say we would like to traverse the map(array) we just created. A way of traversing
	// it is by creating an iterator of the same type as the map, and that we equate to
	// the .begin() or .end()...
	std::map<int, std::string > ::iterator it = dic.begin(); 
	
	// so say we would like to access the values of the iterator. So the way in which
	// we should think of the iterator is that it is almost accessing the indices of 
	// the constructed map. If we have incorporated pairs, then it will have a "first"
	// and a "second" object which refer to the different elements at the given index.
	// For us to drive the iterator forth, we do it++, the iterator++ so we retrieve
	// the new pair. 
	// std::cout << it->first << " :: " << it->second << std::endl;



	// this do while statement is to count the number of digits there are in the 
	// given integer. 
	do
	{
		++number_of_digits;
		convertee /= base;
	} while (convertee);

	for (size_t i = 0; i < number_of_digits; i++)
	{

	}

	wprintf(L"The number of digits: %d", number_of_digits);


	return 0;
}
