#include<bits/stdc++.h>
#define MAX 1000005
using namespace std;

int n,k,m;
long long  f[MAX], a[MAX];

int dp(int x)
{
    if(f[x]!=0)
    {  
        return f[x];
    }
  
    for(int i=1; i <= n; ++i)
    {
        f[x] += a[i]*dp(x-i);
        
    }
    return f[x] %=m;
}


int main()
{
    cin >> n >> k >> m;

    for(int i=1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for(int i=1; i <= n; ++i)
    {
        cin >> f[i];
        f[i] %= m;
    }

    cout << dp(k)%m << "\n";

    return 0;
}