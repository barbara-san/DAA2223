#include <iostream>
#include <string>
#include <climits>
#include <list>
#include <cmath>
#include <set>

using namespace std;

double distance(double x1, double x2, double y1, double y2) {
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

// Classe que representa um no
class Node
{
public:
    double x; double y;
    double dist;
    int i;
    list<pair<int, double>> adj;
    Node* dad;

};


class Graph
{
public:
    int n;
    Node *nodes;

    Graph(int n){ // Constructor: chamado quando um objeto Graph for criado
        this->n = n;
        nodes = new Node[n]; // +1 se os nos comecam em 1 ao inves de 0
    }

    ~Graph(){ // Destructor: chamado quando um objeto Graph for destruido
        delete[] nodes;
    }
    void addSarda(int i, int x, int y) {
        nodes[i].i = i;
        nodes[i].x = x;
        nodes[i].y = y;
    }

    void addLinks() {
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (i != j) nodes[i].adj.push_back({j, distance(nodes[i].x, nodes[j].x, nodes[i].y, nodes[j].y)});
            }
        }
    }

    double prim() {
        //Node r = nodes[0];
        for (int i = 0; i < n; i++){
            nodes[i].dist = INT_MAX;
            nodes[i].dad = nullptr;
        }
        nodes[0].dist = 0;

        set<pair<double, int>> q;

        for (int i = 0; i < n; i++){
            q.insert({nodes[i].dist, i});
        }

        while (!q.empty()){

            pair<double, int> u = *q.begin();
            q.erase(u);

            for (auto edge : nodes[u.second].adj){
                Node& v = nodes[edge.first];
                if (q.find({v.dist, v.i}) != q.end() && edge.second < v.dist) {
                    q.erase({v.dist, v.i});
                    v.dad = &nodes[u.second];
                    v.dist = edge.second;
                    q.insert({v.dist, v.i});
                }
            }
        }

        double count = 0;
        for (int i = 0; i < n; i++) {
            Node* a = nodes[i].dad;
            if (a != nullptr) count += distance(a->x, nodes[i].x, a->y, nodes[i].y);
        }
        cout << count << endl;
        
        return 0;
    }

};

int main(){

    int n; cin >> n;
    Graph g(n);

    for (int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        g.addSarda(i, a, b);
    }
    g.addLinks();

    g.prim();

    return 0;
}
