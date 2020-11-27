#include<iostream>

using namespace std;

int a[300001], rest_p[15000001], p[15000001], sub_gcd[15000001];

int gcd(int x, int b) {
    return (b > 0)? gcd(b, x % b) : x; 
}

// totient function
void sieve_of_euler() {
    int k = 1;
    for(int i = 2; i < 15000001; ++i) {
        if(!rest_p[i])
            rest_p[i] = p[k++] = i;
        for(int j = 1; i * p[j] <= 15000001; ++j) {
            rest_p[i*p[j]] = p[j];
            if(i % p[j] == 0)
                break;
        }   
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int g = a[0];
    sieve_of_euler();
    // remove the actual gcd
    for(int i = 1; i < n; ++i)
        g = gcd(a[i], g);

    for(int i = 0; i < n; ++i)
        a[i] /= g;

    
    // find the max subset diveded by a common prime 
    for(int i = 0; i < n; ++i) {
        int j = a[i]; 
        while(j > 1) {
            int is_equal = rest_p[j];
            sub_gcd[rest_p[j]]++;
            while(rest_p[j] == is_equal) {
                j /= rest_p[j];
            }
        }
    }

    int maxximum = 0;
    for(int i = 0; i < 15000001; ++i)
        maxximum = max(maxximum, sub_gcd[i]);

    if(maxximum > 0)
        cout << n - maxximum << endl;
    else cout << "-1\n";
    return 0;
}