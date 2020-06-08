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


int grau[MAXN];
vector<int> grafo[MAXN];

// it's necessary because after remove a conection between two vertices, 
// it can come before an already taken vertice. 
priority_queue<int, vector<int>, greater<int>> list; 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, a, b;

    cin >> n >> m;

    for(int i = 0; i < m; ++i) {
        cin >> a >> b;
        grafo[a].pb(b);
        grau[b]++;
    }

    for(int i = 0; i < n; ++i) {
        if(!grau[i]) {
            list.push(i);
        }
    }

    int ini = 0;
    vector<int> ans;
    while(!list.empty()) {
        int atual = list.top();
        list.pop();

        for(int i = 0; i < (int)grafo[atual].size(); ++i) {
            int u  = grafo[atual][i];
            grau[u]--;
            if(!grau[u]) 
                list.push(u);
        }
        ans.pb(atual);
    }

    if((int)ans.size() == n) {
        for(auto i: ans) 
            cout << i << endl;
    } else {
        cout << "*" << endl;
    }

    return 0;
}