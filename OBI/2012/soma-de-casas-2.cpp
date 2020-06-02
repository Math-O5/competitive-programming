// problem:
// https://olimpiada.ic.unicamp.br/pratique/p2/2012/f2/soma/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 100200

int main()
{
    int n, casas[MAXN], k;
    
    // input 
    cin >> n;
    
    int i = 0;
    while(i < n) {
        cin >>  casas[i];
        ++i;
    }
    
    cin >> k;
    
    // for each house, find the match
    // lower_bound => O (log n)
    // this runs at least => O (n) 
    // then complexity is upperbound => U (n log n)
    int a = 0, b = 0;
    i = 0;
    while(a + b != k && i < n) {
        a = casas[i];
        b = *lower_bound(casas + i, casas + n, k - a);
        ++i;
    }
    
    cout << a << ' ' << b << endl;
    
    return 0;
}
