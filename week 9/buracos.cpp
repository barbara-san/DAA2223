#include <iostream>
#include <string>
#include <map>
#include <climits>
#include <list>
#include <set>

using namespace std;

// Classe que representa um no
class Node
{
public:
    list<pair<int, int>> adj; // Lista de adjacencias
    int distance;             // Distancia ao no origem da pesquisa
};

// Classe que representa um grafo
class Graph
{
public:
    int n;       // Numero de nos do grafo
    Node *nodes; // Array para conter os nos

    Graph(int n){ // Constructor: chamado quando um objeto Graph for criado
        this->n = n;
        nodes = new Node[n]; // +1 se os nos comecam em 1 ao inves de 0
    }

    ~Graph(){ // Destructor: chamado quando um objeto Graph for destruido
        delete[] nodes;
    }

    void addLink(int a, int b, int c){
        nodes[a].adj.push_back({b, c});
    }

    // Algoritmo de Dijkstra
    void bellman(int s){

        // Inicializar nos como nao visitados e com distancia infinita
        for (int i = 0; i < n; i++){
            nodes[i].distance = INT_MAX/2;
        }
        nodes[s].distance = 0;

        for (int i = 1; i < n; i++){
            for (int u = 0; u < n; u++){
                for (auto edge : nodes[u].adj){
                    int v = edge.first;
                    int cost = edge.second;
                    if (nodes[u].distance + cost < nodes[v].distance){
                        nodes[v].distance = nodes[u].distance + cost;
                    }
                }
            }
        }

        for (int u = 0; u < n; u++){
            for (auto edge : nodes[u].adj){
                int v = edge.first;
                int cost = edge.second;
                if (nodes[u].distance + cost < nodes[v].distance){
                    cout << "possivel" << endl;
                    return;
                }
            }
        }
        cout << "impossivel" << endl;
    }
};

int main(){
    int c; cin >> c;
    
    for (int j = 0; j < c; j++){
        int n, m; cin >> n >> m;
        Graph g(n);

        for (int i = 0; i < m; i++){
            int a, b, t; cin >> a >> b >> t;
            g.addLink(a, b, t);
        }

        g.bellman(0);

    }
    return 0;
}
