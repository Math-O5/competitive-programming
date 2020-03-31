#include<iostream>
#include<queue>
#define MAX 100000
using namespace std;

const int INF = 0x3f3f3f3f;

int pai[MAX];

struct Aresta {
    int a, b, w;
    Aresta(int a, int b, int w): a(a), b(b), w(w) {}
};

struct comp {
    bool operator()(Aresta const& a, Aresta const& b) {
        return a.w > b.w;
    }
};

vector<Aresta> mst;
priority_queue<Aresta, vector<Aresta>, comp> pq;
int n, m, a , b, w;

int find(int x)
{
    if(pai[x]==x)
        return x;
    return find(pai[x]);
}

void join(int x, int y)
{
    x = find(x);
    y = find(y);

    pai[x] = y;
}

void kruskal()
{
    for(int i = 1; i <= m; ++i)
    {
        pai[i] = i;
    }

    for(int i = 1; i <= m; ++i)
    {
        Aresta aresta = pq.top();
        pq.pop();
        if( find(aresta.a) != find(aresta.b))
        {
            join(aresta.a, aresta.b);
            mst.push_back(aresta);
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) 
    {
        cin >> a >> b >> w;
        Aresta adj(a, b, w);
        pq.push(adj);
    }

    kruskal();
    // imprimir a MST
    for(int i = 1;i < n;i++) cout << mst[i].a << " " << mst[i].b << " " << mst[i].w << "\n";
    
    return 0;
}