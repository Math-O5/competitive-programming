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

// -1 2 4 -3 5 2 -5
// the max sum of a array is 
// there is no max element #{} -1, -2, -5
// the array only contain one max element at k. #{1}, -1, 9, -2, -8, 7, -9
// the subarray consist of a subarray that end at k-1 position, followed by k. #{>1}

// sum = 0 = max(array[k], array[k]+sum)
// best = max(best, sum)

// sum = 10 = max(2, 10)


int ans = 0;
int caminho(int x, int y)
{
    if(campo[x][y] == fim) {
        ans++;
        return 1;
    }
    //cout << campo[x][y] << ' ' << x << ' ' << y << '\n';
    campo[x][y] = -1; //already seen it
    if(x+1 < n && campo[x+1][y]>0)
    {
        //ans =
        caminho(x+1, y);
        if(ans > 0)
            return ans++;
    }
    if(y+1 < m && campo[x][y+1]>0)
     {
        //ans =
        caminho(x, y+1) + 1;
        if(ans > 0)
            return ans++;
    }
    if(x-1 >= 0 && campo[x-1][y]>0)
    {
        //ans =
        caminho(x-1, y) + 1;
        if(ans > 0)
            return ans++;
    }
   
    if(y-1 >= 0 && campo[x][y-1]>0)
    {
        //ans = 
        caminho(x, y-1) + 1;
        if(ans > 0)
            return ans++;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    cin >> n >> m;
    //memset(component, -1 , sizeof(MAX)*n);
    
    for(int i = 0; i < n ; ++i)
    {
        for(int j = 0; j < m ; ++j)
        {
            cin >> campo[i][j];
            if(campo[i][j] == ini)
            {
                a = i;
                b = j;
            }
        }
    }
    cout << caminho(a, b)+1 << '\n';
    
    return 0;
}
