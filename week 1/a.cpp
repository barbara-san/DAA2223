#include <iostream>
using namespace std;

int main() {
    int n, b = 0, a;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == 42) b++;
    }
    cout << b << endl;
    return 0;
}
