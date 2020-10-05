// Ali Rassolie

#include <iostream>
// make sure to have quotation for
// the path to the eigen header files
// currently, we have the Eigen header
// folder in the same directort as the cpp
#include "Eigen/Dense"

//using namespace Eigen;



// IMPORTANT TO NOTE
// The reason why there is so much documentation about
// iterating over and using the non-zero values
// is because the sparsematrix' is to minimize the 
// memory usage, by converting the zeros to less
// memory intensive objects. This can occur by virtue of 
// representing the zeros in some way. 
//
// Thus when we read that they want to iterate over the
// non-zero values, remember that. 

int main(int argc, char const *argv[])
{
	// this creates a matrix, 2-dimensional, 
	// with 4 elements in total. 
	Eigen::MatrixXd m(6,3);
	// this will output a matrix of [[0,0],[0,0]]
	std::cout << m << "\n";

	// this will change the values of the components of the matrix, index
	// -wise. 
	m(0,0) = 55;
	m(0,1) = 186;

	std::cout << m << "\n";

	// the MatrixXd.rows() method
	// returns the rows of the matrix
	std::cout << m.rows() << "\n";
	// like-wise, the MatrixXd.cols()
	// method returns the columns of the 
	// matrix. 
	std::cout << m.cols() << "\n";

	// MatrixXd::outersize() seems to provide
	// the columns of the object. 
	int a = m.outerSize();
	std::cout << a;
	return 0;
}