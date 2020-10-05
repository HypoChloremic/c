// This will contain the method definitions

#include <iostream>
#include <fstream>
#include <string>

// if bool = "r", then you will input shit.
// if bool = "w" then you will read the shit.

std::string openThis(char filePath[], char state[], char input[]){
    // instantiating the data-stream
    // For reading 
    std::cout << state << "\n";
    
    // It seems that the paramters for funcs are merely pointers, ie memory addresses
    // hence, in order to access the valus, we need to refer to them
    if (*state == 'r'){
        std::cout << "[openThis] Reading\n";
        // we gots i-fstream (ifstream) and o-stream (ostream) 
        // which seem to have different effects.
        std::ifstream file;
        // we will read the file.
        file.open(filePath, std::ios::out);
        char output[500];

        if(file.is_open()){
            while(!file.eof()){
                file >> output;
                return output;
                }
        }
        
        else{
            std::cout << "[openThis] We got issues with the outputter\n";
            char error[] = "Problem\n";
            return error;
            }
        }
        
    // For writing
    else {
        std::cout << "[Global] Writing\n";
        // We will input to the file.
        std::ofstream file;
        file.open(filePath);
        if (file.is_open()){
            file << input;
            file.close();
            char finished[] = "We be done babe";
            return finished;
            }
            
        else{
            std::cout << "[openThis] We gots issues with the inputter";
            char error[] = "Error";
            return error;
            }
        }
    }