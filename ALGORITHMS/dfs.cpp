#include <iostream>
#include<vector>
#include<queue>
#define MAX 100000
using namespace std;

int component[MAX];
vector<int> grafo[MAX];
const int fim = 3, ini = 2;
int campo[1001][1001], n, m;

void dfs(int v)
{
    for(int i = 0; i < grafo[v].size(); ++i)
    {
        if(component[grafo[v][i]]==-1)
        {
            component[grafo[v][i]] = component[v];
            dfs(grafo[v][i]);
        }
    }
}
