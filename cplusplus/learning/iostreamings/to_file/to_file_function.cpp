#include <iostream>
#include <fstream>

//using namespace std;

int main(){
	// working with the file
	std::ofstream file;
	file.open("random_output.txt");
	file << "This text is streamed directly into the file.\n";
	file.close();

	return 0;
}
