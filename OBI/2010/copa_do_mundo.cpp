#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
  
  queue <int> a;
  int c[2];

  
  int  b[2],
       n = 8,
       j = (int)'A';
 

   for(int i = 0; i < n; ++i)
   {
      cin >> b[0] >> b[1];
      
      if(b[0] >= b[1])
      {
          a.push((j));
      }
      else a.push(j+1);
      j += 2;
   }
     
    while(n > 1)
    {
         n /= 2;
        for (int i = 0; i < n; ++i)
        {
            c[0] = a.front();
            a.pop();
            c[1] = a.front();
            a.pop();
      
            cin >> b[0] >> b[1];
      
            if(b[0] >= b[1])
            {
                 a.push(c[0]);
            }
            else a.push(c[1]);
        }
    }
  
   
  c[0] = a.front();
  printf("%c\n", (char)c[0]);
  
  return 0;
}