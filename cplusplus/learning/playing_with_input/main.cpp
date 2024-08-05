#include <iostream>
#include <string>

int sumDigits(const std::string& val){
	int number = std::stoi(val);
	return (number % 10) + (number / 10);
}

bool luhn(const std::string& val){
	std::cout << val << std::endl;
	int nDigits = val.length();
	int currVal = 0;
	bool second = true;
	int sum = 0;
	for (int i = nDigits - 2; i>=0; i--) {
		currVal = val[i] - '0';
		if (second==true){
			currVal *= 2;
		}
		if (currVal > 10){
			currVal = (currVal % 10) + (currVal / 10);
		}
		sum += currVal;
		second = !second;
		
	}
	int checkSum = (10 - (sum % 10)) % 10;
	if (checkSum == (val[nDigits-1] - '0')){
		return true;
	} else {
		return false;
	}
}

int main(){
	// while(std::cin >> value){
	// } 
	const std::string val = "8304040911";
	// std::cout << luhn(val) << std::endl;	
	std::cout << sumDigits("25") << std::endl;
	return 0;
}
