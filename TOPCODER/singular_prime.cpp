//Singular prime problem Problem Code: DXVI04
//From codechef

#include <iostream>
#include<bitset>
#include<vector>

using namespace std;

bitset<100000>bs;
vector<int> primes;


// 10^9 = 1, => (0, ..., 8) => subtract 1, (1, ..., 9)
// 123 % 9 = ( 1 * 10^2 + 2 * 10^1 + 3 * 10^0 ) % 9 = 1 + 2 + 3
int sumAll(int n) {
    return ((n - 1)%9 + 1);
}

// Crivo on O(n), takes a bit of memore unecessary in this case
void crivo() {
    bs.set();
    
    bs[0] = bs[1] = 0;
    for(int i = 2; i < 100000; ++i) {
        if(bs[i]) 
            primes.push_back(i);
        for(int j = 0; j < primes.size() && i*primes[j] < 100000; ++j) {
            bs[i*primes[j]] = 0;
        }
      
    }
}

int main()
{
    int l, u, t, sum;
    crivo();
    
    cin >> t;
    while(t--) {
        cin >> l >> u;

        // ceck range
        while(l <= u) {
            
            // is prime
            if(bs[l]) {
               sum = l;
               
               // while is prime
               while((bs[sum] && sum > 9)) {
                    
                    sum = sumAll(sum);
                    
                    // if is not prime
                    while(!bs[sum] && sum > 1) {
                        sum--;    
                    }
                    
                    
               }
               
                sum = max(2, sum);
                cout << sum << ' ';
            }
            ++l;
        }
        cout << '\n';
        
    }

    return 0;
}
 
