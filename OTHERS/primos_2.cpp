//Codigo de exemplo
#include<iostream>

using namespace std;

int x;

void primo(int n)
{
 
    for(int i = 2; i*i<=n;++i)
    {
        if(n % i == 0) 
        {
           return;
            
        }
        
    }
    cout << n << ' ';
}

int main(){
  cin >> x;
  
  for(int i=2; i<=x; ++i) primo(i);
  
  
  return 0;
}
