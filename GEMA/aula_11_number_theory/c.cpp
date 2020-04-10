#include <iostream>
#include<math.h>
using namespace std;
 
typedef long long int ll;
 
// 2 2 2 3 3 5 7  = 5*7*8*9
ll b, ans = 0;

int main()
{   
    cin >> b;
    for (ll i = 1; i * i <= b; i++) { 
        if (b % i == 0) { 
   
            if (b / i == i) 
                ans++; 
            else 
                ans += 2; 

        } 
    }
    cout << ans << '\n';
    return 0;
}
