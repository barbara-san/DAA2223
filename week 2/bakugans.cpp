#include <iostream>
using namespace std;
//std::ios_base::sync_with_stdio(false);


int main() {
    int n;
    cin >> n;
    int list[n];
    list[0] = 0;
    for (int i = 1; i < n + 1; i++) {
        int m;
        cin >> m;
        list[i] = list[i - 1] + m;
    }

    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << list[b] - list[a-1] << endl;
    }
    return 0;
}
