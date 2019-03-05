#include <bits/stdc++.h>

using namespace std;

int dp[1002][400];
int w[1002];
int v[400];

int find_sum(int s, int n)
{
  
   if(dp[s][n] != -1)
   {
       return dp[s][n];
   }
   
   if(n == 0 || s == 0) return 0;
   
   if(w[n] > s)
   {
       return dp[s][n] = find_sum(s, n-1);
   }
   
       int op1 = v[n] + find_sum(s-w[n], n-1);
       int op2 = find_sum(s, n-1);
       return dp[s][n] = max(op1, op2);
   
   
}

int main()
{
 
    int j = 1,s = 1,n = 1;

   
    //S is the capacity of the knapsack and the n is the amount of itens.
    while(cin >> s >> n) {
    
    if(s == 0 && n == 0) return 0;
    
    
    //Set dp with all values -1
    memset(dp, -1,sizeof(int)*1002*400);
    
     for(int i = 1; i <= n; ++i)
    {
        cin >> w[i] >> v[i];
    }
 
      //If there is/are item, find the most value that we can obtain:
   
      cout << "Teste" << ' ' << j << "\n" <<  find_sum(s, n) << "\n" << "\n";
      ++j;
    }
 return 0;   
}