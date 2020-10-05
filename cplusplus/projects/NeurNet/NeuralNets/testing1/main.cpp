#include <string>
#include <iostream>
#include <fstream>
#include "Open.h"
//It seems that when you use namespace std
//one wont be needing to write std::cout and instead
//just write cout
using namespace std;

int main(int argc, char **argv)
{
    cout << "[GLOBAL] Initiating program\n";
    
    // Parameters for the openThis() method
    // This actually works haha!
    char first[]  = "C:\\Users\\Ali Rassolie\\Documents\\prwork\\cplusplus\\projects\\NeurNet\\NeuralNets\\testing1\\blah.txt";
    char second[] = "r";
    char third[]  = "NULL";

    string o = openThis(first, second, third);
    cout << o << "\n";
    cout << "Finishing program \n";
	return 0;
}

