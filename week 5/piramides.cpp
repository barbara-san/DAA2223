#include <iostream>
using namespace std;

int main() {
    int n, d;
    cin >> n;
    cin >> d;
    long long count[n][n];
    bool dam[n][n];
    long long countt = 0;
    long long c, p;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            count[i][j] = 0;
            dam[i][j] = false;
        }
    }

    for (int i = 0; i < d; i++) {
        cin >> c >> p;
        dam[n-c][p-1] = true;
    }

    for (int i = 0; i < n; i++) {
        if (i == 0) count[i][0] = 1;
        if (dam[0][0] == true) break;
        for (int j = 0; j < i+1; j++) {
            if (dam[i][j] == true) count[i][j] = 0;
            else {
                if (j != i)
                    count[i][j]+=count[i-1][j];
                if (j != 0)
                    count[i][j]+=count[i-1][j-1];
                if (i == n-1) countt += count[i][j];
            }
        }
    }
    
    cout << countt << endl;

    return 0;
}
