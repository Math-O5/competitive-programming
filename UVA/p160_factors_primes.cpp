/*
    Input n
    Output n is prime or not.

    Crivo:
        Check if a integer number bigger than 1 can divide them.

        Ingenius approch:
            Check all (2, n-1);
        Better:
            Check all (2, n/2);
        Better:
            Check all (2, sqrt(n))
            because n / sqrt(n) * sqrt(n) <= 1,
        Better:
            Check all primes in range (2, sqrt(n))
            complexity: O(sqrt(n)/log(sqrt(n)))
*/

#include<iostream>
#include<vector>
#include<bitset>
#include<map>
#define MAX 1000001

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef map<int, int> mii;

vi primes;      // table ofprimes 
bitset<MAX> bs; // 
ll _sieve_size;
mii factors[MAX];
int ans[MAX];
int component[MAX];

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
            primes.push_back((int)i);
        }
    }
}

/*
    Wise check if n is prime
*/
bool isPrime(int n) 
{
    if(n <= _sieve_size) return bs[n];
    for(int i = 0; i < (int)primes.size() && (ll)primes[i]*primes[i] <= n; ++i)
    {
        if(n % primes[i] == 0)
            return false;
    }
    return false;
}

// Find al factos of N
vi primefactors1(ll n)
{
    vi factor;
    for(auto p : primes) 
    {
        while(n % p == 0)
        {
            n /= p;
            factor.push_back(p);
        }
    }
    if(n != 1) factor.push_back(n);
    return factor;
}

// Find al factos of N
mii primefactors2(mii factor, ll n)
{
    ll index = 0, p = primes[index];
    while(n != 1 && p <= n) 
    {
        while(n % p == 0)
        {
            n /= p;
            factor[index]++;
        }
        p = primes[++index];
    }
    return factor;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;

    sieve(100);
    while(scanf("%d", &n), n > 0)
    {
        for(int i = 2; i <= n; ++i)
        {
            if(!component[i]) 
            {
                component[i] = 1;
                factors[i] = primefactors2(factors[i-1], i);
            }
        }
        printf("%3d! =", n);

        int index = 1;
        for(mii::iterator it = factors[n].begin(); it != factors[n].end(); ++it)
        {
            if(index <= 15)
                ++index;
            else {
                index = 1;
                printf("\n      ");
            }
            printf("%3d", it->second);
        }
        puts("");
    }
    return 0;
}