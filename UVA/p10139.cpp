/*
    This runTimeOut, check the second verion. p10139-2.cpp
*/
#include<iostream>
#include<bitset>
#include<vector>
#include<map>
#define MAX 1000000

using namespace std;

typedef long long int ll;
typedef vector<long long int> vi;
typedef map<long long int, long long int> mii;

bitset<MAX> bs;
vi primos;

void sieve()
{
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i <= MAX; ++i)
    {
        if(bs[i]) {
            for(ll j = i*i; j <= MAX; j += i)
            {
                bs[j] = 0;
            }
            primos.push_back(i);
        }
    }
}

mii factoration(ll n)
{
    mii m;
    ll index = 0, p = primos[index];
    while(n > 1 && p*p <= n)
    {
        while(n % p == 0)
        {
            n /= p;
            m[p]++;
        }
        ++index;
        p = primos[index];
    }
    if(n > 1) m[n]++;
    return m;
}

ll get_power(ll n, ll p) 
{
    ll res = 0;
    for(ll power = p; power <= n; power *= p)
    {
        res += n / power;
    }
    return res;
}

int main()
{
    ll n, m;
    sieve();
    while(cin >> n >> m)
    {
        mii mFactors;
        mFactors = factoration(m);

        int ok = 0;
        for(mii::iterator it = mFactors.begin(); it != mFactors.end(); ++it)
        {
            if(get_power(n, it->first) >= it->second)
            {
                ok = 1;
                continue;
            }
            ok = 0;
            break;
        }
        
        if(m == 1)
            ok = 1;
        if(!ok)
            cout << m << " does not divide " << n << "!\n"; 
        else
            cout << m << " divides " << n << "!\n";
    }
    return 0;
}