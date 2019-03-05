#include<bits/stdc++.h>

int main ()
{
    int n, max = 0, k =0;
    scanf("%d",&n);
    int v[n],i;
    for( i = 0; i<n; ++i)
    {
       scanf("%d",&v[i]);
       max += v[i];
    }
    max = max/2;
    i = 0;
    while(i<max)
    {
        i += v[k];
        ++k;
    }
    
    printf("%d", k);
    return 0;
}
