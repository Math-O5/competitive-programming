#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#define MAX 10000
const int INF = 0x3f3f3f3f;
using namespace std;

int n,
     m, 
    processados[MAX],
    distancia[MAX];     // distance from infinity
vector<int> vizinhos[MAX], edge[MAX];

void dijkstra(int s)
{
    for(int i = 1; i <= n; ++i)
        distancia[i] = INF;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distancia[s] = 0;
    pq.push(make_pair(distancia[s], s));

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for(int i = 0; i < vizinhos[u].size(); ++i)
        {
            int v = vizinhos[u][i];
            int w = edge[u][i];
            if(distancia[v] > distancia[u] + w)
            {
                distancia[v] = distancia[u] + w;
                processados[v] = u;
                pq.push(make_pair(distancia[v], v));
            }
        }
    }
}
// <  1.in
// 5 9 1 5
// 1 2 4
// 1 3 2
// 2 3 3
// 2 4 2
// 2 5 3
// 3 2 1
// 3 5 5
// 3 4 4
// 5 4 1
int main()
{
    int m, fonte, s, x, y, w;
    cin >> n >> m >> fonte >> s;
    for(int i = 0; i < m; ++i)
    {
        cin >> x >> y >> w;
        vizinhos[x].push_back(y);
        edge[x].push_back(w);
    }

    dijkstra(fonte);

    cout << distancia[3];
    return 0;
}