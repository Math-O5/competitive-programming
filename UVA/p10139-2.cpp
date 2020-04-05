#include<iostream>

using namespace std;

typedef long long int ll;

ll mdc(ll a, ll b) { return (b == 0)? a : mdc(b, a % b); }

void divi(ll n, ll m)
{
    ll a = n, b = m;
    if(a == 0) a = 1;
    else if(a >= b) {
        b = 1;
    } else {
        while(a != 1 && b > 1)
        {
            ll num = mdc(max(a, b), min(a, b));
            
            if(b % num == 0)
                b /= num;
            --a;
        }
    }

    if(b != 1)
        cout << m << " does not divide " << n << "!\n"; 
    else
        cout << m << " divides " << n << "!\n";
}

int main()
{
    ll n, m;
    while(cin >> n >> m)
    {  
        divi(n, m);
    }
    return 0;
}