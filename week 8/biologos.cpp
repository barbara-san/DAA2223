#include <iostream>
#include <list>
#include <cmath>

using namespace std;

class Node {
public:
    list<int> adj;  // Lista de adjacencias
    bool visited;   // Valor booleano que indica se foi visitado numa pesquisa
    int distance;   // Distancia ao no origem da pesquisa
    Node() {        // Nao e preciso mais nada porque adj ja foi criada
    };              // mas queria mostrar que em C++ tambem existem construtores
};

class Graph {
public:
    int n;          // Numero de nos do grafo
    Node *nodes;    // Array para conter os nos
    int **arr;
    int *ex;
    int d, r;

    Graph(int n) {  // Constructor: chamado quando um objeto Graph for criado
        this->n = n;
        nodes = new Node[n+1];  // +1 se os comecam em 1 ao inves de 0
        arr = new int*[n+1];
        ex = new int[n+1];
        d = 0;
        r = 9999;
        for (int i{}; i < n+1; i++)
            arr[i] = new int[n+1];
    }

    ~Graph() { // Destructor: chamado quando um objeto Graph for destruido
        delete[] nodes;
        delete[] ex;
        for (int i = 0; i < n+1; i++)
            delete[] arr[i];
        delete[] arr;
    }

    void fillEx() {
        for (int i = 1; i < n+1; i++) {
            ex[i] = 0;
            for (int j = 1; j < n + 1; j++) {
                ex[i] = max(ex[i], arr[i][j]);
            }
        } 
    }

    void getDR(){
        for (int i = 1; i < n + 1; i++) {
            d = max(d, ex[i]);
            r = min(r, ex[i]);
        }
        cout << d << endl << r << endl;
    }

    void getCentrais(){
        bool first = true;

        for (int i = 1; i < n + 1; i++) {
            if (first && ex[i] == r) {cout << i; first = false; continue;}
            if (ex[i] == r) cout << ' ' << i;
        }
        cout << endl;
    }

    void getPerifericos(){
        bool first = true;

        for (int i = 1; i < n + 1; i++) {
            if (first && ex[i] == d) {cout << i; first = false; continue;}
            if (ex[i] == d) cout << ' ' << i;
        }
        cout << endl;
    }

    void addLink(int a, int b) {
        nodes[a].adj.push_back(b);
        nodes[b].adj.push_back(a);
    }
  
    void bfs(int v) {
        list<int> q;
        for (int i=1; i<=n; i++) nodes[i].visited = false;
        
        q.push_back(v);
        nodes[v].visited = true;
        nodes[v].distance = 0;
        int maxi = 0;
        while (q.size() > 0) {
            int u = q.front(); q.pop_front();
            arr[v][u] = arr[u][v] = nodes[u].distance;
            maxi = max(maxi, nodes[u].distance);
            //cout << u << " [dist=" << nodes[u].distance << "]" << endl;
            for (auto w : nodes[u].adj)
                if (!nodes[w].visited) {
                q.push_back(w);
                nodes[w].visited  = true;
                nodes[w].distance = nodes[u].distance + 1; 	  
            }
        }
    }
};

int main() {
    int n, e, a, b;
    
    cin >> n >> e;
    Graph g(n);
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        g.addLink(a, b);
    }

    for (int i = 1; i < n + 1; i++) g.bfs(i);

    g.fillEx();
    g.getDR();
    g.getCentrais();
    g.getPerifericos();

    return 0;
}