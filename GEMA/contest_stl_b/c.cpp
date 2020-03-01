#include<bits/stdc++.h>
using namespace std;
#define MAX 200003
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n, m, aux;
    priority_queue<long long int, vector<long long int>, greater<long long int>> shirt[3][3];
    long long int v[MAX];
    long long int a[MAX];
    long long int b[MAX];
    cin >> n;
    for(long long int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    for(long long int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for(long long int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    for(long long int i = 0; i < n; ++i)
    {
       shirt[a[i]-1][b[i]-1].push(v[i]);
    }
    cin >> m;
    for(long long int i = 0; i < m; ++i)
    {
        cin >> aux;
        --aux;
        long long int minI = 0, minJ = 0;
        long long int min = 1000000001;
        for(long long int j = 0; j < 3; ++j)
           if(!shirt[aux][j].empty())
            {
                if(shirt[aux][j].top() < min)
                {
                    minI = aux; minJ = j;
                    min = shirt[aux][j].top();
                }
           }
        for(long long int j = 0; j < 3; ++j)
            if(!shirt[j][aux].empty())
            {
                if(shirt[j][aux].top() < min)
                {
                    minI = j; minJ = aux;
                    min = shirt[j][aux].top();
                }
            }
        if(min < 1000000001)
        {
            cout << shirt[minI][minJ].top() << ' ';
            shirt[minI][minJ].pop();
        } else {
            cout << -1 << ' ';
        }
    }
    cout << '\n';
    return 0;
}