#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

int main() {

    int a; cin >> a;
    int r; cin >> r;
    map<int, int> m;

    for (int i = 0; i < a+r; i++){
        string s; cin >> s;

        if (s == "BAK") {
            int b; cin >> b;
            if (m.find(b)!=m.end()) m[b]++;
            else m[b] = 1;
        }

        else if (s == "MAX") {
            cout << m.rbegin()->first << endl;
            if (m.rbegin()->second==1) m.erase(m.rbegin()->first);
            else m.rbegin()->second--;
        }

        else if (s == "MIN") {
            cout << m.begin()->first << endl;
            if (m.begin()->second==1) m.erase(m.begin()->first);
            else m.begin()->second--;
        }
    }
    

    return 0;
}
