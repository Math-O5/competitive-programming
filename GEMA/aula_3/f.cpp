#include <iostream>
#include<math.h>
using namespace std;
 
int main()
{
    long long int n, k;
    cin >> n >> k;
    if(n>=1 && k ==1)    
        cout << 1 << '\n';
    else if(k > 0 && k%2==0)
    {
        // 1    2 3 4 5    6 7 8 9    10 11 12 13
        // 1 || 2 4 8 6 || 2 4 8 6  || 2 4  8  6
        long long int ans = (n-1)/4;
        if( ((n-1)%4 == 1 && k==2) || ((n-1)%4 == 2 && k<=4) || ((n-1)%4 == 3 && k!=6))
            ++ans;
        cout << ans << '\n';
        
    }
    else
        cout << 0 << '\n';
    return 0;
}