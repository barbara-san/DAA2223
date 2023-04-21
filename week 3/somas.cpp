#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int bsearch(int v[], int low, int high, int key, int f) {
    int middle;
    while (low < high) {
        middle = low + (high - low)/2;
        if (key == v[middle]) return middle;
        else if (key < v[middle]) high = middle;
        else if (key > v[middle]) low = middle + 1;
    }
    if (v[low] > key) return low;
    return f;
}

int main() {
    int n, q;
    cin >> n;
    int v[n] = {0};

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int m = (n*(n-1))/2;
    int somas[m] = {0};
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            somas[k] = v[i] + v[j];
            k++;
        }
    }

    cin >> q;
    int w[q] = {0};
    for (int i = 0; i < q; i++) {
        cin >> w[i];
    }

    sort(somas, somas + m);

    for (int i = 0; i < q; i++) {
        int b = bsearch(somas, 0, m-1, w[i], m-1);
        if (somas[b] == w[i]) cout << somas[b] << endl;
        else if (b == 0) cout << somas[b] << endl;
        else if (abs(somas[b]-w[i]) > abs(somas[b-1]-w[i])) cout << somas[b-1] << endl;
        else if (abs(somas[b]-w[i]) < abs(somas[b-1]-w[i])) cout << somas[b] << endl;
        else cout << somas[b-1] << " " << somas[b] << endl;
    }
    return 0;
}