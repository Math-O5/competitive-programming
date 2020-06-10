#include<iostream>
#include <algorithm>
using namespace std;

struct consulta {
   int ini, 
       fim;
};

bool compare (const consulta& a, const consulta& b) {
   return (a.ini < b.ini);
}

int main () {
   int n, count = 0;
   cin >> n;
   
   consulta x[n];
   
   for(int i = 0;i < n; ++i) {
      cin >> x[i].ini >> x[i].fim;  
   }

   sort(x, x + n + 1, compare);

   count = 1;
   int takenFim = x[0].fim;

   for(int i = 1;i < n; ++i) {
      
      // pode pegar
      if(takenFim <= x[i].ini) {
         count++;
         takenFim = max(takenFim, x[i].fim);
      } else if(takenFim > x[i].ini) {
         // troco por uma que gere menos conflito
         takenFim = min(x[i].fim, takenFim);
      }
   }
   cout << count;
return 0;
}
