#include <iostream>
#include <algorithm>

using namespace std;

int calcMinDays(const int& n) {
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else {
        int res = 1 + calcMinDays((n + 1) / 2);
        return res;
    }
}

int main(int argc, char* argv[]) {
    int n;

    cin >> n;
    cout << calcMinDays(n);

    //return 1;
}