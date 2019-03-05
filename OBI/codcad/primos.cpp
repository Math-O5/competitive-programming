//Codigo de exemplo
#include<iostream>

using namespace std;

long long int n;

void primo()
{
    if(n==1)
    {
        cout << 'N';
        return;
    }
    for(int i = 2; i*i<n;++i)
    {
        if(n % i == 0) 
        {
           cout << 'N';
           return;
            
        }
        
    }
    cout << 'S';
}

int main(){
  cin >> n;
  primo();
  
  
  return 0;
}
