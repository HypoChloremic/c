#include <stdio.h>
#include <iostream>
#include "MathOp.h"



using namespace std;
cout << "[GLOBAL] Initializing\n"; 
// matrix declaration. 
vector< vector<float> > firstVector(10)  = {5.0,6.0,8.0,8.0,9.0,10.0,11.0,12.0,13.0,14.0};
vector< vector<float> > secondVector(10) = {2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0};
size_t upper_limit = ARRAY_SIZE(firstVector);

float firstMatrix[2][4]  = {{4,4,4,4},
                           {5,5,5,5}};
                           
float secondMatrix[4][2] = {{3,30},
                            {6,60},
                            {7,70},
                            {8,80}};
const size_t ROWS    = ARRAY_SIZE(firstMatrix);
const size_t COLUMNS = ARRAY_SIZE(firstMatrix[0]);
const size_t PRODUCT_ROWS = ARRAY_SIZE(secondMatrix);


int main(int argc, char **argv)
{
    cout << "[GLOBAL] Array size of firstMatrix: " << ARRAY_SIZE(firstMatrix[0]) << "\n";
    
    // note that when one passes an array to a function it will start only to refer to the first
    // index value which is an issue, hence in order for this to function correctly,
    // we will need to pass the size_t from the place that the array is declared. 
    MathOp mathOpInstance;
    float dotProduct    = mathOpInstance.dot(firstVector, secondVector, upper_limit);
    int matMulProduct   = mathOpInstance.matmul(firstMatrix, secondMatrix, ROWS, COLUMNS, PRODUCT_ROWS);
    
    cout << "[GLOBAL] the dot product of the provided matrices:" << dotProduct << "\n";
    cout << "[GLOBAL] the dot product of the provided matrices:" << matMulProduct << "\n";
    
	return 0;
}
