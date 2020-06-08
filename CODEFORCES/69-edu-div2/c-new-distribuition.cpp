// problem: 
// https://codeforces.com/problemset/problem/1167/C
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h> // memset
#include <algorithm> // lower_bound

using namespace std;

#define fs first
#define sd second
#define pb push_back

const int MAXN = 5*1e5 + 10;
const int INF = 0x3f3f3f3f;

int pai[MAXN],
    grau[MAXN];

int find(int x) {
    if(pai[x] == x)
        return x;
    return pai[x] = find(pai[x]);
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) 
        return;
        
    if(grau[x] >= grau[y]) {
        grau[x] += grau[y];
        pai[y] = x;
    } else {
        grau[y] += grau[x];
        pai[x] = y;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k, a, b;
    cin >> n >> m;
    
    for(int i = 0; i <= n; ++i) {
        pai[i] = i;
        grau[i] = 1;
    }
    
    for(int i = 0; i < m; ++i) {
        cin >> k;
        if(k > 0)
            cin >> a;
        for(int j = 1; j < k; ++j) {
            cin >> b;
            join(a, b);
            a = b;
        }
    }

    for(int i = 1; i <= n; ++i) {
        cout << grau[find(i)] << ' ';
    }

    cout << endl;
    cout << endl;

    return 0;
}