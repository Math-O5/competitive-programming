#include <iostream>
#include <string>

using namespace std;

const int INF = 0x3f3f3f3f;

int main()
{
    int t, n, k, ans, tol;
    string s;
    
    cin >> t;
    
    while(t--) {
        cin >> n >> k >> s;
        tol = 0;
        
        for(int i = 0; i < n; ++i) {
            if(s[i] == '1') tol++;
        }
        
        ans = tol; // the number of total lamps is the answer because we can simple turn of them.
        for(int i = 1; i <= n; ++i) {
            
            //int turnOn = 0, // turnOn is how many lamps are on in the interval
            int    prefix = 0; // prefix mesuare if there's more ligths of or on in interval. 
            for(int t = i; t <= n; t += k) {
                if(s[t-1] == '1') {
                    //turnOn += 1;
                    prefix += 1;
                } else {
                    prefix = max(0, prefix - 1);
                }
                ans = min(ans, tol - prefix);
            }
            // is prefix is positive igual a zero, then turn on the off lamps int he range 
            // if(prefix >= 0) {
                // tol - turnOn is the total lamps on minus the lamps that is already on in range
                // k - prefix is how much lamps must go on
            //}
            
        }
        
        cout << ans << endl;
    }

    return 0;
}
