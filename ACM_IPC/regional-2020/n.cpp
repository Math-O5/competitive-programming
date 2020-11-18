
#include<iostream>
#include<vector>
#include<bitset>
#include<map>
#include<set>
#define MAX 1000001

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;

vi primes;      // table ofprimes 
bitset<MAX> bs; // 
ll _sieve_size;
set<ll> factors;

const int INF = 0x3f3f3f;

/*
    Create a Erastotenes's Crivo
*/
void sieve(ll upperbound)
{
    _sieve_size = upperbound + 1;
    bs.set(); //set all bits to 1
    bs[0] = bs[1] = 0;
    for(ll i = 2; i <= _sieve_size; ++i) 
    {
        if(bs[i])
        {
            for(ll j = i*i; j <= _sieve_size; j += i)
            {
                bs[j] = 0;
            }
            primes.push_back((ll)i);
        }
    }
}
// Find al factos of N
void primefactors2(ll n)
{
    ll index = 0, p = primes[index];
    int maxx = (int)primes.size();
    while(n != 1 && p <= n) 
    {
        while(n % p == 0)
        {
            n /= p;
            factors.insert(p);
        }
        if(index + 1== maxx) {
            return;
        }
        p = primes[++index];
        
    }

    // return factor;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    ll aux;
    factors.clear();
    sieve(1000000);

    cin >> m >> n >> k;
    for(int i = 0; i < n; ++i) {
        cin >> aux;
        primefactors2(aux);

    }

    for(int i = 0; i < k; ++i) {
        cin >> n >> m >> aux;
    }
   
    for(set<ll>::iterator it = factors.begin(); it != factors.end(); ++it)
    {
        cout << *it << ' ';
    }
    cout << '\n';
    
    return 0;
}