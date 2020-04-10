#include <iostream>
#include<math.h>
using namespace std;
 
typedef long long int ll;
 
// 2 2 2 3 3 5 7  = 5*7*8*9
ll b, ans;

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int j = 0; j < n; ++j)
    {
        cin >> b;
        ans = 0;
        for (ll i = 1; i * i <= b && ans <= 3; i++) { 
            if (b % i == 0) { 
    
                if (b / i == i) 
                    ans++; 
                else 
                    ans += 2; 
            } 
        }

        if(ans == 3)    
            cout << "YES" << '\n';
        else cout << "NO\n";
    }
    return 0;
}
