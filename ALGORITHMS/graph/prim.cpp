 #include <iostream>
#include<queue>
#include<vector>
#define MAX 10000
using namespace std;

const int INF = 200000;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // weight and vertex
vector<int> adj[MAX], w[MAX]; // vertex adjacent to ith
int n, m, a, b, c, dist[MAX], component[MAX]; // distance from origh

// Return the sum of the Minimum Spanning Tree from the Graph
int prim(int s) 
{
    for(int i = 0; i < n; ++i)
        dist[i] = INF;
    dist[s] = 0;
    pq.push(make_pair(dist[s], s));
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        component[u] = -1;
        
	// For each neighbot of u
        for(int i = 0; i < adj[u].size(); ++i)
        {
            int v = adj[u][i];

	    // If the new arest is smaller than the previos, then update it
            if(dist[v] > w[u][i] && !component[v]) {
                dist[v] = w[u][i];
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < n; ++i)
    {
        sum += dist[i];

    }
    return sum;
}

int main()
{
    // numbers vertex and conections
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        w[a].push_back(c);
        w[b].push_back(c);
    }
    cout << prim(0) << '\n';

    return 0;
}
