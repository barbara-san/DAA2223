#include <iostream>
using namespace std;

int * least(int s[], int k, int coins[], int n, int use[]) {
    coins[0] = 0;
    for (int i = 1; i < k+1; i++) {
        coins[i] = 99999999;
        for (int j = 0; j < n+1; j++) {
            if (s[j] <= i && 1+coins[i-s[j]] < coins[i]) {
                coins[i] = 1+coins[i-s[j]];
                use[i] = s[j];
            }

        }
    }
    return coins;
}

int main() {
    int n;
    int *x;
    cin >> n;
    int s[n];

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int p; cin >> p;

    for (int i = 0; i < p; i++) {
        int kk; cin >> kk;
        int coins[kk+1] = {0};
        int use[kk+1] = {-1};
        x = least(s, kk, coins, n, use);
        int m = *(x+kk);
        cout << kk << ": [" << m << "]";
        int kkk = kk;
        for (int i = 0; i < m; i++) {
            cout << ' ' << use[kkk];
            kkk -= use[kkk];
        }
        cout << endl;
    }
    
    return 0;
}
