#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef struct {
  int freq;
  char c;
  int pos;
} ADN;

struct compareADN {
    bool operator()(const ADN & a1, const ADN & a2) {
        if (a1.freq > a2.freq) return true;
        if (a1.freq < a2.freq) return false;
        return (a1.pos < a2.pos);
    }
};

int main() {

    string s;
    cin >> s;
    ADN v[26] = {{0, 'A', -1}, {0, 'A', -1}, {0, 'A', -1}, {0, 'A', -1}, {0, 'A', -1}, {0, 'A', -1}, {0, 'A', -1}, {0, 'A', -1}, {0, 'A', -1}, {0, 'A', -1}, {0, 'A', -1}, {0, 'A', -1}, {0, 'A', -1}, {0, 'A', -1}, {0, 'A', -1}, {0, 'A', -1}, {0, 'A', -1}, {0, 'A', -1}, {0, 'A', -1}, {0, 'A', -1}, {0, 'A', -1}, {0, 'A', -1}, {0, 'A', -1}, {0, 'A', -1}, {0, 'A', -1}, {0, 'A', -1}};

    int i = 0;
    int o = 0;
    while (s[i] != '\0'){
        int m = s[i] - 'A';
        char c = s[i];
        v[m].c = c;
        v[m].freq++;
        if (v[m].freq == 1){v[m].pos = o; o++;}
        i++;
    }

    sort(v, v+26, compareADN());

    for (int b=0; b<26; b++){
        if (v[b].freq == 0) break;
        cout << v[b].c << " " << v[b].freq << endl;
    }
    
    return 0;
}