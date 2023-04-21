#include <iostream>
using namespace std;
#include <algorithm>

struct fu{
    double multa;
    double sum;
    double ratio;
    int days;
    int order;
};

struct compareAAA {
    bool operator()(const fu& p1, const fu& p2) {
        if (p1.ratio > p2.ratio) return true;
        else if (p1.ratio == p2.ratio) {
            if (p1.sum == p2.sum) return (p1.order < p2.order);
            else if (p1.sum < p2.sum) return (p1.multa > p2.multa);
        }
        return false;
    }
};

int main() {
    int n;
    cin >> n;
    fu b[n];
    int sum = 0;
    for (int j = 0; j < n; j++) {
        cin >> b[j].days >> b[j].multa;
        b[j].ratio = b[j].multa/b[j].days;
        b[j].order = j+1;
        sum += b[j].multa;
    }

    for (int j = 0; j < n; j++) {
        b[j].sum = sum - b[j].multa;
        b[j].sum *= b[j].days;
    }

    sort(b, b+n, compareAAA());

    for (int j = 0; j < n; j++) {
        cout << b[0].order;
        if (j != n-1) cout << ' ';
        b[0].ratio = -1;
        sum -= b[0].multa;
        for (int j = 0; j < n; j++) {
            b[j].sum = sum - b[j].multa;
            b[j].sum *= b[j].days;
        }
        sort(b, b+n, compareAAA());
    }
    cout << '\n';

    return 0;
}