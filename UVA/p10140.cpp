#include<iostream>
#include<bitset>
#include<vector>
#include<algorithm>
#include<math.h>
#define MAX 100000
using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
bitset<MAX> bs;
ll n, m;
vi primes;
ll up, low, lower, upper, found;

const int INF = 0x3f3f3f3f;

void sieve()
{
    bs.set();
    bs[0] =  bs[1] = 0;
    for(ll i = 2; i <= MAX; ++i)
    {   
        if(bs[i])
        {
            for(ll j = i * i; j <= MAX; j += i)
            {
                bs[j] = 0;
            }
            primes.push_back(i);
        }

    }
}

bool isPrime(ll u) 
{
    if(u <= MAX) return bs[u];
    for(int i = 0; i < (int)primes.size() && primes[i] <= (ll)sqrt(u); ++i)
    {
        if(u % primes[i] == 0)
            return false;
    }
    return true;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    sieve();
    while(cin >> n >> m)
    {
        found = 1;
        ll j = n-1;
        do {
            j++;

        } while(isPrime(j)!=1 && j <= m);
        low = j;
        lower = j;
        ++j;
        for(ll i = j; i <= m; i += 1)
        {

            if(isPrime(i)) {
                if(found==1)
                {
                    up = i;
                    upper = i;
                    ++found;
                } else if(found > 1)
                {
                    if(up - low > i - j) {
                        low = j;
                        up = i;
                    } else if(upper - lower < i - j)
                    {
                        lower = j;
                        upper = i;
                    }
                }

                j = i;
            }
        }

        if(found <= 1)
        {
            cout << "There are no adjacent primes.\n";
        } else {
            cout << low << ',' << up << " are closest, " << lower << ',' << upper << " are most distant.\n";
        }
            
    }
    return 0;
}