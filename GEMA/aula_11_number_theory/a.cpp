#include<iostream>

#define MAX 100001

using namespace std;

int d[MAX];
int m;
/*
    Wise check if n is prime
*/
int isPrime(int u) 
{
    int i;
    for(i = 2; i * i <= u; i += 1)
    {
        if(u % i == 0)
            return d[i];
    }
    m += 1;

    return  d[u] = m;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 2; i <= n; ++i)
    {
        cout << isPrime(i) << ' '; 
    }
    cout << '\n';

    return 0;
}
