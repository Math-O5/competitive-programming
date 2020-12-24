#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h> // memset
#include <algorithm> // lower_bound
#include <iomanip>
#include <bitset>
    // #include <bits/stdc++.h>

using namespace std;

#define fs first
#define sd second
#define pb push_back
#define vii vector<int>
#define pii pair<int, int>
#define MAXN 120

const int INF = 0x3f3f3f3f;
int n, grafo[MAXN][MAXN], s, t, c, a, b, cost;

bool bfs(int parent[]) 
{ 
    bool visited[n+5]; 
    memset(visited, 0, sizeof(visited)); 
  
    queue <int> q; 
    q.push(s); 
    visited[s] = true; 
    parent[s] = -1; 
    while (!q.empty()) 
    { 
        int u = q.front(); 
        q.pop(); 
  
        for (int i = 1; i <= n; i++) 
        { 
            if (visited[i]==false && grafo[u][i] > 0) 
            { 
                q.push(i); 
                parent[i] = u; 
                visited[i] = true; 
            } 
        } 
    } 
    return (visited[t] == true); 
} 

int flow() {

    int parent[n+5], maxF=0;
    while(bfs(parent)) {
        int minF = INF;
        int u;
        for(int i = t; i != s; i = parent[i]) {
            u = parent[i];
            minF = min(minF, grafo[u][i]);
        }
        for(int i = t; i != s; i = parent[i]) {
            u = parent[i];
           grafo[u][i] -= minF;
        //    grafo[i][u] += minF;
        }
        maxF += minF;
    }
    return maxF;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int it = 0;
    while(cin >> n && n > 0) {
        memset(grafo, 0, sizeof(grafo));
        cin >> s >> t >> c;
        for(int i = 0; i < c; ++i) {
            cin >> a >> b >> cost;
            grafo[a][b] += cost;
            grafo[b][a] += cost;
        }
        cout << "Network " << ++it << '\n';
        cout << "The bandwidth is " << flow() << ".\n\n";

    }


    return 0;
}