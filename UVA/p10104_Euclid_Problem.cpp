#include <bits/stdc++.h>
using namespace std;

//gcd
int mdc(int x, int y, int &a, int &b){
    if(x == 0) { a = 0; b = 1; return y; }
    int a1, b1;
    int c = mdc(y%x,x,a1,b1);
    a = b1-((y/x)*a1); 
    b = a1;
    return c;
    
}

// x*a + y*b = gcd(x,y) = gcd(y, x mod y) or gcd(x mod y, x)
int main(){
    int x, y, a, b, d;
    while(cin>>x>>y) {
        d = mdc(x,y,a,b);
        cout << a << ' ' << b << ' ' << d << endl;
    }
    return 0;
}