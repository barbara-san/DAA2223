#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

/* double dist(double x1, double x2, double y1, double y2) {
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
} */

class Node
{
public:
    int dist;
    list<pair<int, double>> adj;
    Node* dad;
};

class Graph
{
public:
    int n, a, b;
    Node *nodes;

    Graph(int n){ // Constructor: chamado quando um objeto Graph for criado
        this->n = n;
        nodes = new Node[n+1]; // +1 se os nos comecam em 1 ao inves de 0
    }

    ~Graph(){ // Destructor: chamado quando um objeto Graph for destruido
        delete[] nodes;
    }

    void addLink(int x, int y, int c){
        //cout << x << ' ' << y << ' ' << c << endl;
        nodes[x].adj.push_back({y, c});
        nodes[y].adj.push_back({x, c});
    }

    void prim(int r){
        for (int i = 1; i < n + 1; i++){
            nodes[i].dist = 9999999;
            nodes[i].dad = nullptr;
        }
        nodes[r].dist = 0;

        set<pair<double, int>> q;
        for (int i = 1; i < n + 1; i++) q.insert({nodes[i].dist, i});

        while (!q.empty()){
            pair<double, int> tmp = *(q.begin()); q.erase(tmp);
            int u = tmp.second;
            for (auto v : nodes[u].adj){
                if (q.find({nodes[v.first].dist, v.first}) != q.end() && v.second < nodes[v.first].dist){
                    q.erase({nodes[v.first].dist, v.first});
                    nodes[v.first].dad = &nodes[u];
                    nodes[v.first].dist = v.second;
                    q.insert({nodes[v.first].dist, v.first});
                }
            }
        }
    }
};

int main(){

    int a, b, c; cin >> a >> b >> c;
    Graph g(b + 1);

    for (int i = 0; i < c; i++){
        int x, y, p; cin >> x >> y >> p;
        x = (x <= a) ? 1 : x-(a-1);
        y = (y <= a) ? 1 : y-(a-1);
        g.addLink(x, y, p);
    }

    g.prim(1);

    vector<int> aaa;
    int bbb = 0;
    for (int i = 1; i <= b + 1; i++){
        bbb += g.nodes[i].dist;
        //cout << bbb << endl;
        aaa.push_back(g.nodes[i].dist);
    }

    cout << bbb << endl;

    sort(aaa.begin(), aaa.end());
    for (size_t i = 1; i < aaa.size(); i++){
        if (i != 1) cout << ' ';
        cout << aaa[i];
    }
    cout << endl;

    return 0;
}
