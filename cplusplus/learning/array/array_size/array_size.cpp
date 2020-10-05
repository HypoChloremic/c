#include <iostream>

int main(int argc, char const *argv[])
{
	int arr[][3] = {{0,1,2},
					{3,5,1}};
	int rows = sizeof arr / sizeof arr[0];
	int cols = sizeof arr[0] / sizeof(int);

	std::cout << rows << std::endl; // >>> 2
	std::cout << cols << std::endl; // >>> 3
	std::cout << sizeof(int) << std::endl; // >>> 4 (antagligen bytes!)
										   // i.e. 4x32 or 4x64 bits
	return 0;
}