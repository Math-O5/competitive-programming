#include <bits/stdc++.h>

using namespace std;


int main()
{
  long long int m = 1;
 int res;
 
  cin >> m; 
   
   for(int i = 1; m != 0; ++i)
   {
      cout << "Teste" << " " << i << "\n";
      res = 1;
      for(int j = 1; j <= m;++j)
      {
          res *= 2;
      }
      
       
       cout << res -1  << "\n" << "\n";
       
       cin >> m;
       
   }

    return 0;
}
