// Ali Rassolie

#include <iostream>
// make sure to have quotation for
// the path to the eigen header files
// currently, we have the Eigen header
// folder in the same directort as the cpp
#include "Eigen/Dense"

// it is super important to include the 
// sparse header file, haha
#include "Eigen/Sparse"

int main(int argc, char const *argv[])
{
	// say we have a matrix (which can in turn
	// be considered having many vecotrs that 
	// we have put together in a set, column wise). 
	// 
	// if we want to iterate over the vectors and
	// perform an operation, Eigen provides an 
	// optimized way to do so
	// what they do is that they first let you iterate
	// over the MatrixXd::outerSize() i.e. the columns
	// of the matrix, and subsequently
	// access the vectors respective for those columns,
	// with an inneriterator! So the inneriterator
	// corresponds to the currently active (or selected)
	// vector (column). 

	typedef Eigen::SparseMatrix<double> mat(10,12);

	return 0;
}