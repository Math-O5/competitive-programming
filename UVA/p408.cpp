#include<iostream>
#include<string>
#include<string.h>
#include<bitset>
#define MAX 1000000

using namespace std;

bitset<MAX> bs;

int gcd(int a, int b) { return (b == 0)? a : gcd(b, a % b); }

int main () {
    int n, mod;

    while(scanf("%d%d", &n, &mod) != EOF) {
        bs.set();
        if(gcd(n, mod) == 1) {
            printf("%10d%10d    Good Choice\n\n", n, mod);
        } else {
            printf("%10d%10d    Bad Choice\n\n", n, mod);
        }
    }
    return 0;
}