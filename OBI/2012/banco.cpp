#include <bits/stdc++.h>

using namespace std; 

#define maxs 1000007

int clientes[maxs][2];

int main()
{
int n,
    c,
    i = 0,
    ans = 0;
    
    cin >> c >> n;
     
     priority_queue<int, vector<int>, greater<int>> que;
     
     while(--c >= 0) que.push(0);
     
     while(i < n)
     {
         cin >> clientes[i][0] >> clientes[i][1];
         ++i;
     }
     
     i = 0;
     while(i < n)
     {
         int x = que.top();
         que.pop();
         if((x - clientes[i][0]) > 20) ++ans;
         else if((x - clientes[i][0]) <= 0)
         {
                x = clientes[i][0];   
         }
         x += clientes[i][1];
         que.push(x);
         
         ++i;
     }
     
     printf("%d\n", ans);
     
    return 0;
}
