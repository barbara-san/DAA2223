#include <iostream>
using namespace std;
#include <algorithm>

struct fu{
    int i;
    int f;
};

struct compareAAA {
    bool operator()(const fu& p1, const fu& p2) {
        if (p1.i < p2.i) return true;
        else if (p1.i == p2.i) return (p1.f > p2.f);
        return false;
    }
};

int main() {
    int m, n;
    cin >> m;
    cin >> n;
    fu b[n];

    for (int j = 0; j < n; j++) {
        cin >> b[j].i >> b[j].f;
    }

    sort(b, b+n, compareAAA());

    int end = 0, count = 0, tmp = 0;
    while (end < m) {
        for (int j = 0; j < n; j++) {
            if (b[j].i <= end && b[j].f > tmp) tmp = b[j].f;
        }
        count++;
        end = tmp;
        tmp = 0;
    }
    cout << count << endl;

    return 0;
}