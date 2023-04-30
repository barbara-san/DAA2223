#include <iostream>
#define MAX 101
using namespace std;

int n;
bool adj[MAX][MAX];
bool visited[MAX];

void dfs(int v) {
  visited[v] = true;
  for (int i=1; i<=n; i++)
    if (adj[v][i] && !visited[i])
      dfs(i);
}

int main() {

  int edges, a, b;
  int count = 0;
  cin >> n;
  cin >> edges;

  for (int i=0; i<edges; i++) {
    cin >> a >> b;
    adj[a][b] = adj[b][a] = true;
  }

  for (int i = 1; i < n + 1; i++) {
    if (edges == 0) {count = n; break;}
    if (!visited[i]) {
      dfs(i);
      count++;
    }
  }

  cout << count << endl;
  
  return 0;
}
