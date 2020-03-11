#include <iostream>
#include<vector>
#include<queue>
#define MAX 100000
using namespace std;

int component[MAX];
vector<int> grafo[MAX];
const int fim = 3, ini = 2;
int campo[1001][1001], n, m;

void bfs(int v) 
{
    
    queue<int> q;
    q.push(v);
    
    while(!q.empty())
    {
        int no = q.front();
        q.pop();
        for(int i = 0; i < grafo[no].size(); ++i)
        {
            if(component[grafo[no][i]]==-1)
            {
                component[grafo[no][i]] = component[no];
                q.push(grafo[no][i]);
            }
        }
    }
}
