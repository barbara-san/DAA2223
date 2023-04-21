#include <iostream>
#include <algorithm>
using namespace std;

bool pos(int v[], int k, int n, int max) {
    int b = 0;
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > max) return false;
        if (s + v[i] <= max) s += v[i];
        else {b++;s=v[i];}
    }
    if (b+1 > k) return false;
    return true;
}

int bsearch(int v[], int low, int high, int k, int n) {
    int middle;
    while (low < high) {
        middle = low + (high - low)/2;
        if (pos(v, k, n, middle)) high = middle;
        else low = middle + 1;
    }
    return low;
}

int main() {
    int n; cin >> n;
    int v[n] = {0};
    int sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int b;
        cin >> b;
        cout << bsearch(v, 0, sum, b, n) << endl;
    }
    
    return 0;
}