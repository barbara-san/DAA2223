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
    bool **adj;

    Graph(int n){ // Constructor: chamado quando um objeto Graph for criado
        this->n = n;
        nodes = new Node[n + 1];
        adj = new bool*[n + 1];
        for (int i = 0; i < n+1; i++) {
            adj[i] = new bool[n + 1];
            for (int j = 0; j < n+1; j++){
                adj[i][j] = 0;
            }
        }
    }

    ~Graph(){ // Destructor: chamado quando um objeto Graph for destruido
        delete[] nodes;
        for (int i = 0; i < n+1; i++) {
            delete[] adj[i];
        }
        delete[] adj;
    }

    void addLink(int a, int b){
        adj[a][b] = 1;
    }

    void floyd(map<char, int> m){
        for (int i = 1; i <= n; i++){
            adj[i][i] = 1;
        }

        for (int k = 1; k < n+1; k++){
            for (int i = 1; i < n+1; i++){
                for (int j = 1; j < n+1; j++){
                    if (adj[i][k] && adj[k][j]) adj[i][j] = 1;
                }
            }
        }
        cout << ' ';
        char a = 'A';
        for (int k = 1; k < n+1; k++){
            cout << ' ' << a;
            a++;
        }
        cout << endl;
        a = 'A';
        for (int k = 1; k < n+1; k++){
            cout << a;
            for (int i = 1; i < n+1; i++){
                cout << ' ' << adj[k][i];
            }
            a++;
            cout << endl;
        }
        
    }
};

int main(){
    int n;

    cin >> n;
    Graph g(n);

    char city;

    map<char, int> m;
    for (int i = 0; i < n; i++) {
        m['A' + i] = i+1;
    }

    int num;
    for (int i = 0; i < n; i++){
        cin >> city >> num;
        
        for (int j = 0; j < num; j++){
            char connect; cin >> connect;
            g.addLink(m[city], m[connect]);
        }
    }
    g.floyd(m);

    return 0;
}
