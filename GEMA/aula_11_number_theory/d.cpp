// k-rouding
#include <iostream>

using namespace std;

long long int mdc(int a, int b) { return (b == 0)? a : mdc(b, a % b); }

long long power(long long int x) {
    long long i = 1;
    if(x == 0) return 1;
    for(long long it = 0; it < x; ++it) {
        i *= 10;
    }
    return i;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long int a, b;
    cin >> a >> b;
    cout << a*(power(b)/mdc(a,power(b)));
    return 0;
}
