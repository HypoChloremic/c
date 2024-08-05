#include <iostream>
#include <string>

void printStringPointer(const char* str){
	if(str){
		std::cout << str << std::endl;
	}
}

void printStringRef(std::string& str){
	std::cout << &str << std::endl;
}

int main(){
	std::cout << "Hello world" << std::endl;
	const char* s = "Pointer to charlist";
	std::string str = "Ref to string..";
	printStringPointer(s);
	printStringRef(str);
	return 0;
}
