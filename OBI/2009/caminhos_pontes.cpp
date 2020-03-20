#include <iostream>
#include<vector>
#include<queue>
#include<functional>
#define MAX 1200
using namespace std;
const int INF = 0x3f3f3f3f;

int n, m, a, b, c;
vector<int> pontes[MAX], cost[MAX];
int dist[MAX], previ[MAX];

void dijkstra() {
    for(int i = 1; i <= n+1; ++i)
    {
        dist[i] = INF;
    }
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(dist[0], 0));
    
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for(int i = 0; i < pontes[u].size(); ++i)
        {
            int v = pontes[u][i];
            int w = cost[u][i];
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                previ[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {