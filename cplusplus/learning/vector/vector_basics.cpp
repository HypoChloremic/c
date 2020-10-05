#include <vector>
#include <iostream>

int main(){

	std::vector<int> matrix;
	std::vector<int> other_matrix(3); // initializes with size 3. 
	std::vector<int> third_matrix(3, 21); // initializes with size 3. 
	
	matrix.push_back(121); // .push_back is a member function
	std::cout << matrix[0] << matrix.size() << std::endl; // .size() also member function

	return 0;
}

