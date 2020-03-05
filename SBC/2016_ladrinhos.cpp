 
#include<iostream>
#include<vector>
#include<queue>
#define MAX 400
using namespace std;


int h, l, grafo[MAX][MAX];

int bfs(int i, int j)
{
    queue<pair<int,int>> fila;
    fila.push(make_pair(i,j));
    int cor = grafo[i][j], size = 0;
    grafo[i][j] = -1;
    while(!fila.empty())
    {
        ++size;
        pair<int,int> v = fila.front();
        fila.pop();

        if(v.first+1 < h && grafo[v.first+1][v.second]==cor)
        {
            fila.push(make_pair(v.first+1, v.second));
            grafo[v.first+1][v.second] = -1;
        }

        if(v.first-1 >= 0 && grafo[v.first-1][v.second]==cor)
        {
            fila.push(make_pair(v.first-1, v.second));
            grafo[v.first-1][v.second] = -1;
        }

        if(v.second+1 < l && grafo[v.first][v.second+1]==cor)
        {
            fila.push(make_pair(v.first, v.second+1));
            grafo[v.first][v.second+1] = -1;
        }

        if(v.second-1 >= 0 && grafo[v.first][v.second-1]==cor)
        {
            fila.push(make_pair(v.first, v.second-1));
            grafo[v.first][v.second-1] = -1;
        }
    }
    return size;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> h >> l;
    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < l; ++j)
        {
            cin >> grafo[i][j];
        }
    }

    int j = 0, best = 46001;
    for(int i = 0; i < h; ++i)
    {
        for(j = 0; j < l; ++j)
        {
            if(grafo[i][j] != -1)
            {
                best = min(best, bfs(i, j));
            }
        }
    }

    cout << best << '\n';
    return 0;
}
