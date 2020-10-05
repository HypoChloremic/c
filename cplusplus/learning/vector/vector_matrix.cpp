#include <iostream>
#include <vector>

using namespace std;

void print_matrix(int d1, int d2){
	vector<vector<int>> matrix(d1, vector<int> (d2, 0));
	for (int i = 0; i < d1; ++i){
		for(int j = 0; j < d2; ++j){
			cout << matrix[i][j]; 
		}
		cout << endl;
	}
}

int main(){
	int d1, d2;
	while(cin >> d1 >> d2){
		print_matrix(d1, d2);	
}
	return 0;

}
