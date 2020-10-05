#include <iostream>

template<typename... T>
auto foldsum(T... args){
	return (... + args); 
}

int main(){
	int arr[2] = {10, 12};
	std::cout << foldsum(10, 12);
}

