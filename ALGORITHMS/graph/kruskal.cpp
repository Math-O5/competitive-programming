// source:
// https://neps.academy/lesson/196
// https://cp-algorithms.com/graph/mst_kruskal.html

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h> // memset
#include <algorithm> // lower_bound
#include <iomanip>

using namespace std;

#define fs first
#define sd second
#define pb push_back
#define vii vector<int>
#define pii pair<int, int>
#define MAXN 120000

const int INF = 0x3f3f3f3f;

int pai[MAXN], peso[MAXN], n, m, a, b;

// arestas
struct edge {
    int x, y, cost;
    bool operator<(const edge& b) {
        return cost < b.cost; 
    }
};

vector<edge> e, 
             mst;

// union find (DSU)
int find(int x) {
    if(pai[x] == x) 
        return x;
    return pai[x] = find(pai[x]);
}

// Put two teams in same team since now.
void join(int x, int y) {
    x = find(x); y = find(y);
    if(x == y) return;    
    if(peso[x] > peso[y]) {
        pai[x] = y;
        peso[y] += peso[x];
    }
    else {
        pai[y] = x;
        peso[x] += peso[y];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    edge aux;

    cin >> n >> m;

    // initialition, all nodes is themselves fathers, that means each vertex is a component.
    for(int i = 0; i < m; ++i) {
        pai[i] = i;
    }  

    // input
    for(int i = 0; i < m; ++i) {
        cin >> aux.x >> aux.y >> aux.cost;
        e.push_back(aux);
    }

    // Strategy: take the lightless edge which isnot in our component
    sort(e.begin(), e.end());

    for(int i = 0; i < m; ++i) {
        if( find(e[i].x) != find(e[i].y)) {
            join(e[i].x, e[i].y);
            mst.pb(e[i]);
        }
    }

    for(int i = 1; i < n; ++i) 
        cout << mst[i].x << " " << mst[i].y << " " << mst[i].cost << "\n";

    return 0;
}