#include<iostream>
#include<vector>
#include<queue>
#define MAX 10000
using namespace std;

int n, a, b, c;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;;
int component[MAX], previ[MAX];

struct Aresta {
    int x, y, w;
    
    Aresta(int x, int y, int z) : x(x), y(y), w(w) {
        
    }
};

int mst() {
    previ[pq.top().second] = pq.top().first;
    component[pq.top().second] = component[pq.top().first] = 1;
    pq.pop();
    int u, v;
    while(!pq.empty())
    {
        u = pq.top().first;
        v = pq.top().second;
        pq.pop();
        
        previ[v] = u;
        component[u] = component[v] = 1;
    }
    
    return v;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> a >> b >> c;
        pq.push(make_pair(a, b));
    }
    
    int u = mst();
    
    while(previ[u]) {
        cout << previ[u] << ' ';
        u = previ[u];
    }
    return 0;
}