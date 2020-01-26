#ifndef MATHOP_H
#define MATHOP_H
#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))
#include <typeinfo>
#include <string>
#include <iostream>
#include <vector>
// contains the dot-product method. 
/* Supposedly the ifndef which will ask via the preprocessor if the 
 * preprocessor has had the given header defined or called already, 
 * if it hasnt it will continue as true. We move onto defining the preprocessor
 * variable, such that we may use the header. This will work with the preprocessor
 * until it stumbles across the #endif thing. 
 * So if we try to include the header file again later on in the code
 * ifndef will show false, which means that everything between the ifndef and endif
 * will not be included. That is how header files work, they will include replace the
 * include argument with the code in the given header file.
*/ 


const size_t FIRST_MATRIX  = 4;
const size_t SECOND_MATRIX = 2;

class MathOp
{

        public:

            float dot(float firstVector[],  float secondVector[], size_t upper_limit){
                std::cout << "[dot] Initiating dot method\n";

                // We need to check that both of the vectors have the same size. 
                if(sizeof(firstVector) == sizeof(secondVector)){
                    std::cout << "[dot] Both vectors are of the same size\n";
                    
                    // Variable definitions
                    float dotProduct = 0.0;
                    //int   index      = 0;
                    
                    // Performing the actual calculation
                    for(size_t i=0; i < upper_limit; i++){
                        dotProduct += (firstVector[i] * secondVector[i]);
                        //index++;
                        }
                    //std::cout << "[dot] Number of vector elements: " << index+1 <<"\n";
                    return dotProduct;
                }
                else{
                    std::cout << "[dot][Error] the vectors are not of the same size.\n";
                    return 0.0;
                    }
                }
            
            /*Seems that pointers are extremely dangerus, cuz u are passing pters around. 
             * 
             * */
            
            std::vector< std::vector<float> > matmul(float firstMatrix[][FIRST_MATRIX], float secondMatrix[][SECOND_MATRIX], size_t HEIGHT, size_t WIDTH, size_t PRODUCT_HEIGHT){
                
                // Checking whether the matrices have a transposed relationship is a bit irritating I would say
                std::cout << "[matmul] Initiating matmul\n";
                
                std::vector< std::vector<float> > productMatrix(WIDTH);
                // We need to iterate through the rows and columns
                for(size_t row = 0; row < PRODUCT_HEIGHT; row++){
                for(size_t col = 0; col < WIDTH; col++){
                for(size_t inn = 0; inn < HEIGHT; inn++)
                            
                            
                            productMatrix[row][col] += firstMatrix[row][inn] * secondMatrix[inn][col];
                            
                            // Commenting on the shit. 
                            std::cout << productMatrix[row][col] << " ";
                        }
                    std::cout << "\n";
                    
                    }
                return productMatrix;
                }
};

#endif

