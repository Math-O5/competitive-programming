// Run on 0.01ms case test! 

#include <iostream>
#include<string.h>
#include<vector>
#include<queue>
#define MAX 200000
using namespace std;

int n, m, k, c;
int dist[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> adj[MAX];
vector<int> peso[MAX];


int dijkstra()
{
    dist[k] = 0;
    pq.push(make_pair(0, k));
    
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if(u == c-1) continue;
            for(int i = 0; i < adj[u].size(); ++i)
            {
                int v = adj[u][i];
                int w = peso[u][i]; 
                if(u < c-1 && v != u+1) continue;
                if(dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
    }
    
    return dist[c-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, d;
    while(cin >> n >> m >> c >> k && n > 0 && m > 0 && k > 0 && c > 0)
    {
        for(int i = 0; i < n; ++i) {
            dist[i] = MAX;
        }
        for(int i = 0; i < m; ++i) {
            cin >> a >> b >> d;
            adj[a].push_back(b);
            adj[b].push_back(a);
            peso[a].push_back(d);
            peso[b].push_back(d);
        }
        cout << dijkstra() << '\n';
        
        while(!pq.empty())
            pq.pop();
        for(int i = 0; i < n; ++i) {
            adj[i].clear();
            peso[i].clear();        
        }
    }

    return 0;
}
