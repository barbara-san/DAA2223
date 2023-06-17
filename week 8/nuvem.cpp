#include <iostream>
#include <list>
#include <cmath>

using namespace std;
int l, c;
int mint[251][251];
bool mvis[251][251];

bool isIn(int i, int j, int l, int c){
    return ((0 <= i && i <= l-1) && (0 <= j && j <= c-1));
}
  
void bfs(int v, int b) {
    list<pair<int, int>> q;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            mvis[i][j] = false;
        }
    }
    
    q.push_back({v, b});
    mvis[v][b] = true;
    while (q.size() > 0) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop_front();


        if (isIn(i+1, j, l, c) && !mvis[i+1][j]) {
            q.push_back({i+1, j});
            mvis[i+1][j] = true;
            if (mint[i][j] + 1 < mint[i+1][j]) mint[i+1][j] = mint[i][j] + 1;
        }

        if (isIn(i, j+1, l, c) && !mvis[i][j+1]) {
            q.push_back({i, j+1});
            mvis[i][j+1] = true;
            if (mint[i][j] + 1 < mint[i][j+1]) mint[i][j+1] = mint[i][j] + 1;
        }

        if (isIn(i-1, j, l, c) && !mvis[i-1][j]) {
            q.push_back({i-1, j});
            mvis[i-1][j] = true;
            if (mint[i][j] + 1 < mint[i-1][j]) mint[i-1][j] = mint[i][j] + 1;
        }

        if (isIn(i, j-1, l, c) && !mvis[i][j-1]) {
            q.push_back({i, j-1});
            mvis[i][j-1] = true;
            if (mint[i][j] + 1 < mint[i][j-1]) mint[i][j-1] = mint[i][j] + 1;
        }
        
    }
}

int main() {
    cin >> l >> c;
    char m[l][c];
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++){
            cin >> m[i][j];
            if (m[i][j] == '#') mint[i][j] = 0;
            else mint[i][j] = 9999;
        }
    }

    int mi = 9999;
    int ma = 0;
    for (int i = 0; i < l; i++){
        for (int j = 0; j < c; j++){
            if (m[i][j] == '#') bfs(i, j);
        }
    }

    for (int i = 0; i < l; i++){
        for (int j = 0; j < c; j++){
            if (m[i][j] == 'A') mi = min(mi, mint[i][j]);
            if (m[i][j] == 'A') ma = max(ma, mint[i][j]);
        }
    }

    cout << mi << ' ' << ma << endl;

    return 0;
}