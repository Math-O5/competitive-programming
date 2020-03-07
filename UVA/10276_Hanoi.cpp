#include<iostream>
#include<vector>
//#include<map>
//#include<queue>
#include<math.h>
#include<string.h>
#define MAX 100
using namespace std;

int t, n, maxn;

bool isQuare(int v) 
{
    int s = sqrt(v);
    return (s*s == v)? true : false;
}

void backtrack(int num, int k, int q[])
{
    if(k == n)
    {
        maxn = max(maxn,num-1);
        return;
    }

    if(!q[k])
    {
        q[k] = num;
        backtrack(num+1, k, q);
    } else {
        int aux=0;
        for(int i = 0; i <= k; ++i)
        {
            if( isQuare(q[i] + num) )
            {
                aux = q[i];
                q[i] = num;
                backtrack(num+1, k, q);
                q[i] = aux;
                break;
            }    
        }
        if(aux==0)
            backtrack(num, k+1, q);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q[MAX];
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        cin >> n;
        backtrack(1, 0, q);
        cout << maxn << '\n';
        maxn = 0;
        memset(q, 0, n*sizeof(int));
    }
    return 0;
}