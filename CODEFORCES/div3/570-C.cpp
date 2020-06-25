// problem:
// binary search
// https://codeforces.com/contest/1183/problem/C
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    long long int q, n, k, a, b, ans;

    cin >> q;
    while(q--) {
        cin >> k >> n >> a >> b;
    
        long long int c = k - (n*a);
        if(c > 0) {
            ans = n;    
        } else {
            long long int turns = (-c + (a - b)) / (a - b);
            if(turns <= n) {
                ans = n - turns;
            } else ans = -1;
        }
        
        cout << ans << endl;
    }

    return 0;
}
