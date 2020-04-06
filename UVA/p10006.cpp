#include<iostream>
#include<bitset>
#include <cstdlib>
#include <ctime>

#define MAX 65001

using namespace std;

typedef long long int ll;
ll n;
bitset<MAX> bs;

void sieve()
{
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i <= MAX; ++i)
    {
        if(bs[i])
        {
            for(ll j = i * i; j <= MAX; j += i)
            {
                bs[j] = 0;
            }
        }
    }
}

/*
    a  pertence [2, n-1],

    a^n % n = a

    a^(n-1) === 1 (mod n)
*/
ll mod(ll k, ll pk)
{
    if(pk == 0) return 1;
    if(pk % 2 == 0)
    {
        ll x = mod(k, pk/2);
        return ((x%n)*(x%n))%n;
    }
    return ( (k%n) * (mod(k, pk-1)%n) ) % n;
}

bool fermatTest()
{
    srand(time(NULL));
    for(int i = 0; i < 10; i++)
    {
        ll k = (ll)(rand() % (n-2))+2, ans;

        // from 1 to n-1, but 1 already has been token.
        ans = mod(k, n);
        //cout << k << ' ' << ans << endl;
        // if it's congruente with 1
        if(ans == k)
            continue;
        else return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    while(cin >> n, n > 0) {
        if(bs[n] || (fermatTest() == bs[n])) {
            cout << n << " is normal.\n";
        } else {
            cout << "The number " << n << " is a Carmichael number.\n";
        }
    }

    return 0;
}