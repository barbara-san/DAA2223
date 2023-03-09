#include <iostream>
#include <cmath>
using namespace std;

double smth (double x1, double y1, double l, double x2, double y2, double r) {
    return (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) <= r*r;
}


double inter(double x1, double y1, double l, double x2, double y2, double r) { 
    double d = sqrt((r*r)/2);
    // nao se intersetam
    if ((x1+l <= x2-r) || (y1+l <= y2-r) || (x1 >= x2+r) || (y1 >= y2+r)) return 0;

    /*double xn = max(x1, min(x2, x1+l));
    double yn = max(y1, min(y2, y1+l));
    if (!(((xn - x2) * (xn - x2) + (yn - y2) * (yn - y2)) <= r * r)) return 0;*/

    // quadrado dentro do circulo
    if ((x2-d <= x1) && (y2-d <= y1) && (x2+d >= x1+l) && (y2+d >= y1+l)) return (l*l);
    if (smth(x1, y1, l, x2, y2, r) && smth(x1+l, y1, l, x2, y2, r) && smth(x1+l, y1+l, l, x2, y2, r) && smth(x1, y1+l, l, x2, y2, r)) return (l*l);
    // circulo dentro do quadrado
    if ((x1+l >= x2+r) && (y1+l >= y2+r) && (x1 <= x2-r) && (y1 <= y2-r)) return (M_PI * r*r);
    
    double area = 0.0;
    if (l > 0.001) {
        area += inter(x1, y1 + l/2, l/2, x2, y2, r);        // subquadrado superior esquerdo
        area += inter(x1 + l/2, y1 + l/2, l/2, x2, y2, r);   // subquadrado superior direito
        area += inter(x1, y1, l/2, x2, y2, r);              // subquadrado inferior esquerdo
        area += inter(x1 + l/2, y1, l/2, x2, y2, r);        // subquadrado inferior direito
    }
    return area;
}

int main() {
    double a, b, c, d, e, f;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d >> e >> f;
        cout << inter(a, b, c, d, e, f) << endl;
    }
    return 0;
}
