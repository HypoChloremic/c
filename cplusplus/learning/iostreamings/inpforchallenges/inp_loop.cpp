#include <iostream>
using namespace std;

int main() {
    int i = 0;
    int sum = 0;
    
    /*
    Supposedly, this way, the loop will be continuing to 
    accept input until the an EOF (End-of-File conidition). This can be done with
    `ctrl + D`
    */
    while (cin >> i) {
        sum += i;
    }
    
    cout << sum << endl;
    
    return 0;
}
