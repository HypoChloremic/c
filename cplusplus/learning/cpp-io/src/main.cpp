#include <exception>
#include <iostream>
#include <istream>
#include <stdexcept>
#include <fstream>
#include <vector>

using namespace std;

void read_data(istream& stream){
	int i = 0;
	while(stream >> i){
		cout << i << endl;
	}
}

string get_file_name(int argc, char** argv){
	if (argv == nullptr){
		cerr << "argv nullptr" << endl;
		throw runtime_error("argv is null");
	}
	string input_file;
	for(int i = 1; i < argc; i++){
		if(argv[i] != nullptr) {
			input_file = argv[i];
		} else {
			cerr << "Error: argv[" << i << "] is null." << endl;
			throw runtime_error("argv is null");
		}
	}
	return input_file;
}

struct Coord {
	float lat;
	float lon;
};



int main(int argc, char** argv){
	if (argv == nullptr){
		cerr << "argv nullptr" << endl;
		return -1;
	}
	string input_file;
	try {
		input_file = get_file_name(argc, argv);
		cout << input_file << endl;

		ifstream file(input_file);
		if (file){
			vector<Coord> buffer;
			float _x, _y;
			while(!file.eof()){
				file >> _x;
				file >> _y;
				buffer.push_back({_x, _y});
			}
			file.close();
			for (const auto& coord : buffer) {
				cout << coord.lat << " " << coord.lon << endl;	
			}
		} else {
			throw runtime_error("Incorrect file name");
		}
	} catch (exception& e){
		cerr << "Error when processing " << endl;
		return -1;
	}

	return 0;
}
