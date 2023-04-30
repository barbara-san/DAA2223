#include <iostream>
#define MAX 9999
using namespace std;

bool p[MAX][MAX];
bool visited[MAX][MAX];

void dfs(int l, int c, int size1, int size2, int &count) {
    visited[l][c] = true;
    count++;
    //cout << count << ' ';
    //cout << "(" << l << "," << c << ")" << endl;

    int bbb, bb, ttt, tt;
    if (l-1 < 0) bbb = l;
    else bbb = l-1;
    if (c-1 < 0) ttt = c;
    else ttt = c-1;
    if (l+1 <= size1-1) bb = l+1;
    else bb = l;
    if (c+1 <= size2-1) tt = c+1;
    else tt = c;

    //cout << "[" << bbb << "," << bb << "]" << endl;
    //cout << "[" << ttt << "," << tt << "]" << endl;

    for (int b = bbb; b < bb+1; b++) {
        for (int t = ttt; t < tt+1; t++) {
            if (p[b][t] && !visited[b][t]){
                //cout << "here";
                dfs(b, t, size1, size2, count);
            }
        }
    }
}

int tamanho(int size1, int size2) {
    int count = 0;
    int tmp = 0;
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (!visited[i][j] && p[i][j]) dfs(i, j, size1, size2, tmp);
            count = max(count, tmp);
            tmp = 0;
        }
    }
    return count;
}

int main() {

    int n; cin >> n;
    int l, c;

    for (int i = 0; i < n; i++) {
        cin >> l >> c;
        for (int j = 0; j < l; j++){
            for (int k = 0; k < c; k++){
                char s; cin >> s;
                if (s == '.') {p[j][k] = false; visited[j][k] = true;}
                else p[j][k] = true;
                //cout << p[j][k] << " ";
            }
            //cout << endl;
        }

        cout << tamanho(l, c) << endl;

        for (int j = 0; j < l; j++){
            for (int k = 0; k < c; k++){
                p[j][k] = false;
                visited[j][k] = false;
            }
        }  
    }
  
    return 0;
}
