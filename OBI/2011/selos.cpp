//Codigo de exemplo
#include<bits/stdc++.h>

using namespace std;

long long int n;

void primo(int x)
{
    if(n<4)
    {
        cout << 'N';
        return;
    }
    for(int i = 2; i<=x;++i)
    {
        if(n % i == 0) 
        {
           cout << 'S';
           return;
            
        }
        
    }
    cout << 'N';
}

int main(){
  cin >> n;
  int x = sqrt(n);
  primo(x);
  
  
  return 0;
}