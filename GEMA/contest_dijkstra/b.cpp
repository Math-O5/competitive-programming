#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#define MAX 100000
 
using namespace std;
 
const int INF = 0x3f3f3f3f; 
 
int n, m, a, x, y, z, b;
int dist[MAX];
vector<int> previ[MAX]; 
vector<int> vizinhos[MAX];
vector<pair<int, int>> aresta[MAX];
vector<int> cost[MAX];
vector<int> ans[MAX];
void dijkstra(int s) 
{
    for(int i = 1; i <= n; ++i)
        dist[i] = INF;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[s] = 0;
    pq.push(make_pair(dist[s], s));
       
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
 
        // if(u == b)
        //     continue;

        for(int i = 0; i < int(vizinhos[u].size()); ++i)
        {
            int v = vizinhos[u][i];
            int w = cost[u][i];
            if(dist[v] > dist[u] + w)
            {
                previ[v].clear();
                previ[v].push_back(u);
                dist[v] = dist[u] + w;
                cout << u << ' ' << v << endl;
                pq.push(make_pair(dist[v], v));
            }
            else if(dist[v] == dist[u] + w)
            {
                previ[v].push_back(u);
                cout << u << " aqui " << v << endl;
            }
        }
    }
}
int find(int i, int j)
{
    if(i == j)
    {
        return 1;
    }

    for(int k = 0; k < int(previ[j].size()); ++k) {
        ans[j].push_back(previ[j][k]);
        ans[previ[j][k]].push_back(j);
        if(find(i, previ[j][k]))
            return 1;
    }
    return 0;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    cin >> n >> m >> a >> b;
    for(int i = 0; i < m; ++i)
    {
        cin >> x >> y >> z;
        aresta[i].push_back(make_pair(x,y));
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
        cout << i << ' ';
        for(int j = 0; j < int(previ[i].size()); ++j)
        {
            cout << previ[i][j] << ' ';
        }
        cout << endl;
    }
    int ok;
    find(a, b); 
    for(int i = 0; i < m; ++i)
    {
        ok = 1; 
        for(int k = 0; k < int(ans[aresta[i][0].first].size()); ++k)
        {
            if(ans[aresta[i][0].first][k]==aresta[i][0].second)
            {
                ok = 0;
                cout << "sim\n";
                break;
            }
        }
        if(ok)
            cout << "nao\n";

    }
    return 0;
}