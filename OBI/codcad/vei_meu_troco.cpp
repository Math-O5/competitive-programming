/**************************************************
 * Mathias Fernandes: Troco (coin change)
 * 
 * Dado n valores moedas, C) possivel entregar o valor m com elas? 
 * Se sim, quais e qual a respectiva quantidade.
 * 
*******************************************************************************/

#include <bits/stdc++.h>


using namespace std;
#define MAX 1000

vector<int> c;
int n,m;

int dp[MAX];

int solve(int x, vector<int> &c){
	
	if(x==0) return 1;
	
	if(x<0) return 0;
	
	if(dp[x]>=0) return dp[x];
	
	for(int i=0;i<c.size();i++)
		if(solve(x-c[i], c)) return dp[x-c[i]]=1;
		
	return dp[x]=0;
}

int main()
{
    memset(dp,-1,sizeof(int)*1000);
    cin >> n >> m;
    int it;
    for(int i = 1; i <= n; ++i)
    {
        cin >> it;
        c.push_back(it);
    }
    
        
    if(solve(m,c)) 
    {
       cout << "S"; 
    }
    
    else 
    {
        cout << "N";
    }
    
    return 0;
}
