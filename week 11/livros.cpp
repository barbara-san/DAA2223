#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
public:
    int n;
    vector<vector<int>> adj; // Lista de adjacencias
    vector<vector<int>> cap; // Matriz de capacidades

    Graph(int n){
        this->n = n;
        adj.resize(n);
        cap.resize(n);
        for (int i = 0; i < n; i++) {cap[i].resize(n);}
    }

    void addLink(int a, int b){
        adj[a].push_back(b);
        adj[b].push_back(a);
        cap[a][b] = 1;
    }

    int bfs(int s, int t, vector<int> &parent){
        for (int i = 0; i < n; i++){parent[i] = -1;}

        parent[s] = -2;
        queue<pair<int, int>> q; // fila do BFS com pares (no, capacidade)
        q.push({s, INT_MAX});    // inicializar com no origem e capacidade infinita

        while (!q.empty()){

            int cur = q.front().first;
            int flow = q.front().second;
            q.pop();

            for (int next : adj[cur]){
                if (parent[next] == -1 && cap[cur][next] > 0){
                    parent[next] = cur;                       // atualizar pai
                    int new_flow = min(flow, cap[cur][next]); // atualizar fluxo
                    if (next == t)return new_flow;            // chegamos ao final?
                    q.push({next, new_flow});                 // adicionar a fila
                }
            }
        }

        return 0;
    }

    int maxFlow(int s, int t){
        int flow = 0;                // fluxo a calcular
        vector<int> parent(n+1);   // vetor de pais (permite reconstruir caminho)

        while (true){
            int new_flow = bfs(s, t, parent); // fluxo de um caminho de aumento
            if (new_flow == 0) break;         // se nao existir, terminar

            flow += new_flow; // aumentar fluxo total com fluxo deste caminho
            int cur = t;
            while (cur != s){ // percorrer caminho de aumento e alterar arestas
                int prev = parent[cur];
                cap[prev][cur] -= new_flow;
                cap[cur][prev] += new_flow;
                cur = prev;
            }
        }

        return flow;
    }
};

int main(){
    int c; cin >> c;
    for (int i = 0; i < c; i++){
        int n, m, a, b;
        cin >> n >> m;

        Graph g(2*n + 2);

        for (int j = 0; j < m; j++) {
            cin >> a >> b;
            //int aaa = n + b;
            //cout << a << ' ' << b << ' ' << aaa << endl;
            g.addLink(a, n + b);
        }
        for (int j = 0; j < n; j++) {
            g.addLink(2*n, j);
            g.addLink(n + j, 2*n + 1);
        }

        int f = g.maxFlow(2*n, 2*n + 1);
        if (f != n) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    
    return 0;
}

// exercicio 42, nice :)
/*
n = 5?
     o0  o5
     o1  o6  
o11  o2  o7  o12
     o3  o8  
     o4  o9  

2*n vs 2*n+1
2*n + oi + of = 2*n + 2
*/

