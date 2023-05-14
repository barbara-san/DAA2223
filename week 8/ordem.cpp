#include <iostream>
#include <cmath>
#include <list>
#include <set>
using namespace std;

bool adj[26][26];
bool visited[26];
list<char> ordem;

void dfs(int v) {
    visited[v] = true;
    for (int i = 0; i < 26; i++) {
        if (adj[v][i] && !visited[i]) {dfs(i);}
    }
    ordem.push_front(v + 'A');
}

void ordemTop() {
    for (int i = 0; i < 26; i++) {
        if (!visited[i]) {dfs(i);}
    }
}

int main() {
    int n; cin >> n;
    set<char> letters;
    string words[n];

    for (int i = 0; i < n; i++) cin >> words[i];
    for (int i = 0; i < 26; i++) visited[i] = false;


    for (int i = 0; i < n - 1; i++) {
        //if (!letters.contains(words[i].at(j)));
        int size = min(words[i].length(), words[i+1].length());
        for (int j = 0; j < size; j++) {
            if (!letters.count(words[i].at(j))) {
                letters.insert(words[i].at(j));
            }
            if (!letters.count(words[i+1].at(j))) {
                letters.insert(words[i+1].at(j));
            }
            if (words[i].at(j) != words[i+1].at(j)) {
                int a = words[i].at(j) - 'A';
                int b = words[i+1].at(j) - 'A';
                adj[a][b] = true;
                //cout << a << ' ' << b << endl;
                //cout << adj[a][b] << endl;
                break;
            }
        }
        
    }

    ordemTop();

    for (char z : ordem) {
        if (letters.count(z)) 
            cout << z;
    }
    cout << "\n";
    
    return 0;
}

