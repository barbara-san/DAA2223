#include <iostream>
using namespace std;
#include <ctype.h>
#include <cmath>
//std::ios_base::sync_with_stdio(false);

int convc(char c) {
    if (c > 'Y') c-=3;
    else if (c > 'W') c-=2;
    else if (c > 'K') c--;
    return (c - 'A');
}

int convd(char c) {
    return (c - '0');
}

int num(string s) {
    char a1 = s[0], a2 = s[1], a3 = s[3], a4 = s[4], a5 = s[6], a6 = s[7];
    int a = 0;
    if (!isdigit(a1)) {
        if (isdigit(a6)) {
            a = convc(a1)*23+convc(a2);
            a = a*10000+convd(a3)*1000+convd(a4)*100+convd(a5)*10+convd(a6); //1
        }
        else{
            a = convc(a1)*23*23*23+convc(a2)*23*23+convc(a5)*23+convc(a6);
            a = a*100+convd(a3)*10+convd(a4) + num("99-ZZ-99") + 1; //4
        }
    }
    else {
        if (isdigit(a6)) {
            a = convc(a3)*23+convc(a4);
            a = a*10000+convd(a1)*1000+convd(a2)*100+convd(a5)*10+convd(a6) + num("99-99-ZZ") + 1; //3
        }
        else {
            a = convc(a5)*23+convc(a6);
            a = a*10000+convd(a1)*1000+convd(a2)*100+convd(a3)*10+convd(a4) + num("ZZ-99-99") + 1; //2
        }
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    string a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << abs(num(b) - num(a)) << endl;
    }
    return 0;
}
