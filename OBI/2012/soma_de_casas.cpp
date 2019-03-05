#include <stdio.h>


int busca(int x, int m, int n, int *v)
{
    int low = m,mid, high = n;
    
    while(low <= high)
    {
         mid = (low + high)/2;
        
        if(v[mid] == x) return mid;
        if(v[mid] < x) low = mid + 1;
        if(v[mid] > x) high = mid - 1;
    }
    
    return mid;
    
}

int main()
{
    int n, k, m;

    scanf("%d",&n);
    
    int v[n];
    
    for(int i = 0; i < n; ++i)
    {
        scanf("%d",&v[i]);
    }
    
    scanf("%d",&k);
    
    //Now is garantee that all numbers are less than k:
    n = busca(k, 0, n, v);
    
    for(int i = 0; i < n; ++i)
    {
        m = busca(k-v[i], 0, n, v);
        if(v[i] + v[m] == k) 
        {
            printf("%d %d\n",v[i], v[m]);
            return 0;
        }
    }
    

    return 0;
}