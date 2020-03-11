#include<iostream>

using namespace std;

const int INF = 0x3f3f3f3f;
int mina[110][110], cost[110][110], n;
int moves[4][2] = {{1,0}, {0,1},{0,-1},{-1,0}};

bool valid(int x, int y)
{
    return (x >= 0 && x < n && y >=0 && y < n)? true : false;
}

int backtracking(int x, int y)
{
    int sup = INF;
    if(x == n-1 && y == n-1)
        return 0;

    for(int i = 0; i < 4; ++i)
    {
        int v1 = x + moves[i][0];
        int v2 = y + moves[i][1];
        if(valid(v1, v2) && cost[v1][v2] > cost[x][y]) {
            cost[v1][v2] = cost[x][y] + mina[v1][v2];
            backtracking(v1, v2);
            sup = min(sup, cost[v1][v2]);
        }
    }
    
    return sup;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i= 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> mina[i][j];
            cost[i][j] = INF;
        }
    }

    cost[0][0] = 0;
    backtracking(0, 0);
    cout << cost[n-1][n-1] << '\n';
    // cout << ".....................\n";
    // for(int i = 0; i < n; ++i)
    // {
    //     for(int j = 0; j < n; ++j)
    //     {
    //         cout << cost[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    return 0;
}