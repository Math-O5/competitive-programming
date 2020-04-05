#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<bitset>
using namespace std;

#define MAX 10000040
typedef vector<long long int> vi;
typedef map<long long int, long long int> mii;
typedef long long int ll;
ll _sieve;
bitset<MAX> bs;
vi prime;

void sieve(int upper)
{
    _sieve = upper + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i <= _sieve; ++i)
    {
        if(bs[i]) {
            for(ll j = i*i; j <= _sieve; j += i) 
            {    
                bs[j] = 0;
            }
            prime.push_back(i);
        }
    }
}

mii factors(ll n) 
{
    mii factors;
    ll index = 0, p = prime[index];
    // ll nmax = (ll)prime.size();
    while(n != 1 && p*p <= n)
    {
        while(n % p == 0)
        {
            n /= p;
            factors[p]++;
        }
        ++index;
        // if(nmax == index) 
        // {
        //     break;
        // }
        p = prime[index];
    }
    if(n!=1) factors[n]++;
    return factors;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    ll n;
    mii m;
    sieve(MAX-1);
    while(cin >> n && n != 0)
    {
        if(n < 0)
            n = -n;
        m = factors(n);
        if(m.size()  > 1)
        {
            mii::iterator it = --m.end();
            ll l = it->first;
            cout << l << '\n';

        }
        else
            cout << -1 << '\n';
    }
    return 0;
}