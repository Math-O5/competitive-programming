#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double r, a, b, ans;

int main()
{
    int n, k;
    cin >> n >> k;
    
    int tmp_k = k;
    
    long long int ans = 1;
    for(int i = n; i > n - k; --i) {
        ans *= i;
    }
    for(int i = 2; i <= k; ++i)
        ans /= i;
        
    cout << ans << endl;
    return 0;
}
