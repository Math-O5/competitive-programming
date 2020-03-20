#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#define MAX 100010
 
using namespace std;
 
const int INF = 0x3f3f3f3f; 
 
int n, m, a, x, y, z, b;
int dist[MAX];
vector<int> previ[MAX]; 
vector<int> vizinhos[MAX];
vector<int> aresta[MAX];
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
 
        if(u == b)
            continue;

        for(int i = 0; i < vizinhos[u].size(); ++i)
        {
            int v = vizinhos[u][i];
            int w = cost[u][i];
            if(dist[v] > dist[u] + w)
            {
                int l = previ[v].size()-1;
                while(l >= 0 && dist[previ[v][l]] > dist[u])
                {
                    previ[v].pop_back();
                    --l;
                }
                previ[v].push_back(u);
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
            else if(dist[v] == dist[u] + w)
                previ[v].push_back(u);
        }
    }
}
 
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    cin >> n >> m >> a >> b;
    for(int i = 0; i < m; ++i)
    {
        cin >> x >> y >> z;
        aresta[x].push_back(y);
        vizinhos[x].push_back(y);
        vizinhos[y].push_back(x);
        cost[x].push_back(z);
        cost[y].push_back(z);
    }
 
    dijkstra(a);
 
    // for(int i = 1; i <= n; ++i)
    //     (dist[i] != INF)? cout << dist[i] << '\n' : cout << -1 << '\n';
 
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j < aresta[i].size(); ++j)
        {
            int ok = 0, u = aresta[i][j], k = 0;
            while(!ok && k < previ[i].size())
            {
                if(previ[i][k] == u) {
                    ok = 1;
                    break;
                }
                ++k;
            }
            k = 0;
            while(!ok && k < previ[u].size())
            {
                if(previ[u][k] == i) {
                    ok = 1;
                    break;
                }
                ++k;
            }

            if(ok)
                cout << "sim\n";
            else
                cout << "nao\n";
        }
    }
    return 0;
}