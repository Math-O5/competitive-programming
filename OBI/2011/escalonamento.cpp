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
#define MAXN 50010

const int INF = 0x3f3f3f3f;

int component[MAXN], grau[MAXN];
vector<int> grafo[MAXN],
            list;

void dfs(int v) {
    for(int i = 0; i < (int)grafo[v].size(); ++i) {
        int u = grafo[v][i];
        grau[u]--;
        if(grau[u] == 0) {
            list.pb(u);
            dfs(u);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, a, b;

    //memset(component, -1, sizeof component);

    cin >> n >> m;

    for(int i = 0; i < m; ++i) {
        cin >> a >> b;
        grafo[a].pb(b);
        grau[b]++;
    }

    for(int i = 0; i < n; ++i) {
        if(!grau[i]) {
            list.pb(i);
        }
    }

    // for(auto i: list) 
    //     dfs(i);

    int ini = 0;
    while(ini < (int)list.size()) {
        int atual = list[ini++];

        for(int i = 0; i < (int)grafo[atual].size(); ++i) {
            int u  = grafo[atual][i];
            grau[u]--;
            if(!grau[u]) 
                list.pb(u);
        }

    }

    if((int)list.size() == n) {
        for(auto i: list) 
            cout << i << endl;
    } else {
        cout << "*" << endl;
    }

    return 0;
}