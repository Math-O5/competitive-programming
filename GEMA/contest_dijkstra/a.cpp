#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#define MAX 100010
 
using namespace std;
 
const int INF = 0x3f3f3f3f; 
 
int n, m, a, x, y, z;
int dist[MAX]; 
vector<int> vizinhos[MAX];
vector<int> cost[MAX];
 
void dijkstra(int s) 
{
    for(int i = 1; i <= n; ++i)
        dist[i] = INF;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(dist[s], s));
       
    dist[s] = 0;
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
 
        for(int i = 0; i < vizinhos[u].size(); ++i)
        {
            int v = vizinhos[u][i];
            int w = cost[u][i];
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> a;
    for(int i = 0; i < m; ++i)
    {
        cin >> x >> y >> z;
        vizinhos[x].push_back(y);
        vizinhos[y].push_back(x);
        cost[x].push_back(z);
        cost[y].push_back(z);
    }
 
    dijkstra(a);
 
    for(int i = 1; i <= n; ++i)
        (dist[i] != INF)? cout << dist[i] << '\n' : cout << -1 << '\n';
 
    return 0;
}