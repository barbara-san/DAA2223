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
    list<pair<int, double>> adj; // Lista de adjacencias
    bool visited;                // No ja foi visitado?
    double distance;             // Distancia ao no origem da pesquisa
};

// Classe que representa um grafo
class Graph
{
public:
    int n;       // Numero de nos do grafo
    Node *nodes; // Array para conter os nos

    Graph(int n){ // Constructor: chamado quando um objeto Graph for criado
        this->n = n;
        nodes = new Node[n + 1]; // +1 se os nos comecam em 1 ao inves de 0
    }

    ~Graph(){ // Destructor: chamado quando um objeto Graph for destruido
        delete[] nodes;
    }

    void addLink(int a, int b, double c){
        nodes[a].adj.push_back({b, c});
    }

    // Algoritmo de Dijkstra
    void dijkstra(int s, int end){

        // Inicializar nos como nao visitados e com distancia infinita
        for (int i = 1; i <= n; i++){
            nodes[i].distance = INT_MAX;
            nodes[i].visited = false;
        }

        // Inicializar "fila" com no origem
        nodes[s].distance = 0;
        set<pair<double, int>> q; // By "default" um par e comparado pelo primeiro elemento
        q.insert({0, s});      // Criar um par (dist=0, no=s)

        // Ciclo principal do Dijkstra
        while (!q.empty()){

            // Retirar no com menor distancia (o "primeiro" do set, que e uma BST)
            int u = q.begin()->second;
            q.erase(q.begin());
            nodes[u].visited = true;
            if (u == end) cout << nodes[u].distance << endl;

            // Relaxar arestas do no retirado
            for (auto edge : nodes[u].adj){
                int v = edge.first;
                double cost = edge.second;
                if (!nodes[v].visited && nodes[u].distance + cost < nodes[v].distance){
                    q.erase({nodes[v].distance, v}); // Apagar do set
                    nodes[v].distance = (double)nodes[u].distance + cost;
                    q.insert({nodes[v].distance, v}); // Inserir com nova (e menor) distancia
                }
            }
        }
    }
};

int main(){
    int n, e, a, b;
    double c;

    cin >> n >> e;
    Graph g(n);

    string p1, p2;
    cin >> p1 >> p2;
    string start = p1;
    string end = p2;

    map<string, int> m;
    m[start] = 1;
    m[end] = 2;
    int count = 3;

    for (int i = 0; i < e; i++){
        cin >> p1 >> p2 >> c;
        if (!m.count(p1)) {m[p1] = count; count++;}
        if (!m.count(p2)) {m[p2] = count; count++;}

        a = m[p1];
        b = m[p2];
        g.addLink(a, b, c);
        g.addLink(b, a, c);
    }

    g.dijkstra(1, 2);

    return 0;
}
