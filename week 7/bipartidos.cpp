#include <iostream>
#define MAX 501
using namespace std;

bool adj[MAX][MAX];
bool visited[MAX];
int colour[MAX];

void dfs(int v, int ind, bool &aaaa) {
    visited[ind] = true;
    for (int i = 1; i < v + 1; i++) {
        //cout << ind << ' ' << i << ' ' << adj[ind][i] << endl;
        if (adj[ind][i] && ind != i){
            if (!visited[i]) {
                colour[i] = (colour[ind] == 1) ? 2 : 1;
                dfs(v, i, aaaa);
                //cout << ' ' << colour[i] << endl;
            }
            else if (colour[ind] == colour[i]) {aaaa = false;}
        }
    }
}

bool checker(int v) {
    colour[1] = 1;
    bool bbbbb = true;
    dfs(v, 1, bbbbb);
    return bbbbb;
}

int main() {
  
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int v, e, a, b;
        cin >> v; cin >> e;

        for (int i = 0; i < e; i++) {
            cin >> a >> b;
            adj[a][b] = adj[b][a] = true;
        }

        if (checker(v)) cout << "sim" << endl;
        else cout << "nao" << endl;

        for (int i = 1; i < v + 1; i++) {
            visited[i] = false;
            for (int j = 0; j < v + 1; j++) {
                adj[i][j] = adj[j][i] = false;
            }
        }

  }
  
  return 0;
}
