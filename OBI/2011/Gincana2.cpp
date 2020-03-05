 #include<iostream>
#include<vector>
#include<queue>
#define MAX 100005
using namespace std;

int n, m, a, b, ok;
vector<int> grafo[MAX];
int component[MAX];

int bfs(int x)
{
    queue<int> fila;
    fila.push(x);
    
    while(!fila.empty())
    {
        int v = fila.front();
        fila.pop();
        
        int filhos = grafo[v].size();
        
        for(int i = 0; i < filhos; ++i)
        {
            if(component[grafo[v][i]]==0)
            {
                component[grafo[v][i]] = component[v];
                fila.push(grafo[v][i]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        grafo[b].push_back(a); //a esta pendurado em b
        grafo[a].push_back(b);
    }
    
    int i = 1, j = 0;
    for(; i <= n; ++i)
    {
        if(component[i]==0)
        {
            component[i] = ++j;
            bfs(i);
        }
    }
    
    cout << j << '\n';
    return 0;
}
