
#include<iostream>
#include<vector>
#include<bitset>
#include<math.h>
#define MAX 1000001

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

bitset<MAX> bs; // 
ll _sieve_size;


/*
    Create a Erastotenes's Crivo
*/
void sieve()
{
    _sieve_size = MAX;
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
        }
    }
}

// find t-prime. (has three number which divides it) 49 = (1, 7, 49)
// all numbers which has 3 divisors is the form (1, p, p²)
int main() {
    ll b;
    int n;
    cin >> n;
    sieve();
    for(int i = 0; i < n; ++i) {
        cin >> b;
        double a = sqrt(b);
        if(fmod(a,1.0)==0 && bs[(int)a]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
