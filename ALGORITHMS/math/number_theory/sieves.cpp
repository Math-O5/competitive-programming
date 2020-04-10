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
#define MAX 1000001

using namespace std;

typedef long long ll;
typedef vector<int> vi;

vi primes;      // table ofprimes 
bitset<MAX> bs; // 
ll _sieve_size;
const int INF = 0x3f3f3f3f;

/*
    Sieve of atkin
    complexity: O(N/log log(N))
    source: https://en.wikipedia.org/wiki/Sieve_of_Atkin
*/
void atkins_sieve(ll upperbound)
{
    
}

/*
    Same backgroundEratotenes
    Complexity: O(N)
*/
void fast_sieve_erastotenes(ll upperbound) 
{
    _sieve_size = upperbound;
    bs.set();
    bs[0] = bs[1] = false;

    // for every number, check if it is prime:
    for(ll i = 2; i <= _sieve_size; ++i) 
    {
        if(bs[i]) // is prime
        {
            primes.push_back((int)i);
        }

        // for every primes numbers mark the multiples with false
        for(ll j = 0; j < (ll)primes.size() && i*primes[j] <= _sieve_size; ++j)
        {
            bs[i*primes[j]] = false;
            if(i % primes[j] == 0) break;
        }

    }
}
/*
    Create a Erastotenes's Crivo
    Complexity: O(N log (log N))
*/
void sieve_erastotenes(ll upperbound)
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

int main() {
    fast_sieve_erastotenes(MAX);
    // for(auto v : primes) {
    //     cout << v << ' ';
    // }
    cout << '\n';
    return 0;
}