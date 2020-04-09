#include <stdio.h>
#include <string.h>

typedef long long ll;
const int MAX = 1e6+5;
bool bs[MAX], vis[MAX];
int head, 
    primes[MAX];

void sieve()
{
    // for all numbers, check if they are primes!
    for(ll i = 2;i < MAX;++i) {
        if(!bs[i])
        {
            primes[++head] = i;
            // while there is multiples to remove, remove them.
            for(ll j = i*i; j <= MAX; j += i)
            {
                bs[j] = 1;
            }
        }
    }
}

// Check if the new values is more far
void maxRange(ll &range, ll a, ll b, ll &p1, ll &p2)
{
    ll r1 = b - a;
    if(range < r1) 
    {
        range = r1;
        p1 = a;
        p2 = b;
    }
}

// Check if the new values is more near
void minRange(ll &range, ll a, ll b, ll &p1, ll &p2)
{
    ll r1 = b - a;
    if(range > r1) 
    {
        range = r1;
        p1 = a;
        p2 = b;
    }
}

int main() 
{
    ll l, r;
    sieve();
    while(scanf("%lld%lld", &l, &r)!= EOF)
    {
        memset(vis, 0, MAX);     
        if(l == 1)
            vis[0] = 1;
        // For all primes
        for(int i = 1; i <= head; ++i)
        {   
            // mark all composite numbers, like 
            // K factor has an upper and lower bound (L / prim [], R / prim [])
            for(ll j = l/primes[i]; j <= r/ primes[i]; ++j) {
                ll aux = primes[i]*j;
                if(j > 1 && aux >= l) vis[aux-l]= 1;
            }    
        }

        ll ok = 0, p, p1, p2, p3, p4, minN =1LL<<60, maxN = 0;
        for(ll i = l; i <= r; ++i) {
            if(vis[i-l]) continue;
            if(ok == 0) {ok = 1;} else {
                minRange(minN, p, i, p1, p2);
                maxRange(maxN, p, i, p3, p4);
            }
            p = i;
        }

        if(!maxN) printf("There are no adjacent primes.\n");
        else printf("%lld,%lld are closest, %lld,%lld are most distant.\n", p1, p2, p3, p4);
    }
    return 0;
}
