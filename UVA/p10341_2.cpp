#include<iostream>
#include<math.h>
#include <cmath>        // std::exp(double)
#include<iomanip>       // std::setprecision(int)

#define EPS 1e-5

using namespace std;

int p, q, r, s, t, u;

double f(double x) {
    return (p*exp(-x)) + (q*sin(x)) + (r*cos(x)) + (s*tan(x)) + (t*pow(x, 2)) + u; 
}

double search() {
    int it = 0;
    double y, ini = 0, fim = 1, x = 0.5;
    while(abs(y = f(x)) >= EPS) {
        if(++it >= 400)
            return -1;
        if(y >= 0) {
            ini = x + EPS;
        } else {
            fim = x - EPS;
        }
        x = (ini + fim)/2;
    }

    return x;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

    while(cin >> p >> q  >> r >> s >> t >> u) {
        double x =  search();
        if(x == -1) {
            cout << "No solution\n";
        } else {
            cout << setprecision(4) << fixed << x << '\n'; 
        }
    }

    return 0;
}