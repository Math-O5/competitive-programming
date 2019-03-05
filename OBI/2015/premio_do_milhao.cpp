#include <bits/stdc++.h>
using namespace std;

int numeros[1000];
long long int soma;

int dias(int x)
{
    int days = 0;
    
    while(soma < 1000000)
    {
        soma += numeros[days];
        ++days;
    }
    
    return days;
}

int main()
{
    int n;
    cin >> n;
 
    for(int i = 0; i < n; ++i)
    {
        cin >> numeros[i];
    }
    
    cout << dias(n);
    
    
    
    return 0;
}