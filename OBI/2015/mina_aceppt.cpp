#include <iostream>
#include<queue>
#include<vector>
#include<string.h>
#define MAX 200
using namespace std;
const int INF = 0x3f3f3f3f;

int n, mina[MAX][MAX];
int dist[MAX][MAX], moves[4][2] = {{1,0}, {0,1}, {-1,0}, {0, -1}};
struct Elemento {
  int first, second, w;  
  
  Elemento(int first, int second, int w) :
    first(first), second(second), w(w)
    {
        
    }
};

bool operator<(const Elemento& a,const Elemento& b)
{
        return a.w < b.w;
}


priority_queue<Elemento> pq;

bool valid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < n)? true: false;
}
void dijkstra()
{
    Elemento e(0, 0, 0);
    pq.push(e);
    dist[0][0] = 0;
    while(!pq.empty())
    {
        e = pq.top();
        pq.pop();
        for(int i = 0; i < 4; ++i)
        {
            int x = e.first + moves[i][0];
            int y = e.second + moves[i][1];
            int w = mina[x][y];
            if(valid(x, y) && dist[x][y] > dist[e.first][e.second] + w)
            {
                Elemento v(x, y, w);
                dist[x][y] = dist[e.first][e.second] + w;
                pq.push(v);
            }
        }
        
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        memset(dist[i], INF, sizeof(int)*MAX);
        for(int j = 0; j < n; ++j)
            cin >> mina[i][j];
    }    
    dijkstra();
    cout << dist[n-1][n-1];
    return 0;
}