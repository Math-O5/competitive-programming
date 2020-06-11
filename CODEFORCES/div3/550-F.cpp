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
#define MAXN 200200

const int INF = 0x3f3f3f3f;

int color[MAXN];
vector<int> grafo[MAXN];

struct edge {
    int a, b;
};

edge ans[MAXN];
int n, m, a, b;


int bfs() {
    queue<int> q;

    q.push(1);

    // decide initial color
    color[1] = 1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int i = 0; i < (int)grafo[u].size(); ++i) {
            int v = grafo[u][i];

            if(color[v] == -1) {
                color[v] = !color[u];
                q.push(v);
            } else if(color[v] == color[u]) {
                return 0;  
            }
        }
    }

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;

    memset(color, -1, sizeof color);

    for(int i = 0; i < m; ++i) {
        cin >> a >> b;
        grafo[a].pb(b);
        grafo[b].pb(a);
        ans[i].a = a; ans[i].b = b;
    }
    

    if(bfs()) {
        cout << "YES\n";
        for(int i = 0; i < m; ++i) 
            // check orientation arest
            cout << (color[ans[i].a] < color[ans[i].b]);
        cout << endl;
    } else {
        cout << "NO\n";
    }

    return 0;
}