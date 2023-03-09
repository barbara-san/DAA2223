#include <iostream>
using namespace std;

int sum(int num) {
    int su = 0;
    while (num >0) {
        su += num%10;
        num /= 10;
    }
    return su;
}

int main() {
    int t, n, k;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        int m = n + 1;
        while (sum(m) != k) m++;
        cout << m << endl;
    }
    return 0;
}
