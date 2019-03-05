#include<bits/stdc++.h>

using namespace std;

int main () {
  int m,n, cont=0;
  cin >> m >> n;
  char mar[m][n];
  for(int i=0;i<m;++i) 
     {
      for(int j=0;j<n;++j)
       {
		      cin >> mar[i][j];
		}
      }
          
    for(int i=0;i<m;++i) 
    {
      for(int j=0;j<n;++j)
      {
         if(mar[i][j]=='#') 
	     {
		    if(mar[i][j+1]=='.' || j+1==n) cont++;
		    else if(mar[i][j-1]=='.' || j-1<0) cont++;
		    else if(mar[i+1][j]=='.' || i+1==m) cont++;
		    else if(mar[i-1][j]=='.' || i-1<0) cont++;
		 }
      }
    }
    cout << cont << "\n";

  return 0;
}
