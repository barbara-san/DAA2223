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
        adj.resize(n + 1);
        cap.resize(n + 1);
        for (int i = 1; i < n + 1; i++) {cap[i].resize(n + 1);}
    }

    void addLink(int a, int b, int c){
        adj[a].push_back(b);
        adj[b].push_back(a);
        cap[a][b] = c;
    }

    int bfs(int s, int t, vector<int> &parent){
        for (int i = 1; i < n + 1; i++){parent[i] = -1;}

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
        int flow = 0;              // fluxo a calcular
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
    int n, e, a, b; cin >> n >> e;
    Graph g(n);

    for (int i = 0; i < e; i++){
        cin >> a >> b;
        g.addLink(a, b, 1);
        g.addLink(b, a, 1);
    }

    int f = g.maxFlow(1, n);
    cout << f << endl;

    return 0;
}