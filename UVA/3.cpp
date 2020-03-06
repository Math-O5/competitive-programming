#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#define MAX 100
using namespace std;

int t, n;
queue<int> q[MAX];

bool isQuare(int v) 
{
    int s = sqrt(v);
    return (s*s == v)? true : false;
}

void backtrack(int num, int k, int noSolve)
{
    if(k == n)
    {
        if(noSolve == num)
            cout << num << endl;
        else {
            noSolve = num;
            k = 0;
        }
        return;
    }

    if(q[k].empty())
    {
        q[k].push(num);
        backtrack(num+1, k);
    }
    else if( isQuare(q[k].front() + num) )
    {
        q[k].push(num);
        backtrack(num+1, k);
    }    
    else 
    {
        backtrack(num, k+1);
    }
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        cin >> n;
        backtrack(1, 0);

        for(int j = 0; j < n; ++j)
        {
            while(!q[j].empty())
            {
                q[j].pop();
            }
        }
    }
    return 0;
}