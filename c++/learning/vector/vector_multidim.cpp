#include<bits/stdc++.h> 
using namespace std; 
int main(){ 

    int n = 10; 
    int m = 3; 

    // Create a vector containing n 
    //vectors of size m.  
    vector<vector<int>> vec(n, vector<int> (m, 121));

    for (int i = 0; i < vec.size(); ++i ){
	for(int j = 0; j < vec[0].size(); ++j){
		cout << vec[i][j] << " ";
	}
	cout << endl;
 
    }
    return 0; 
} 
