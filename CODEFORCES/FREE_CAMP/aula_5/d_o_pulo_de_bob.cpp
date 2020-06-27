#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double r, a, b, ans;

int main()
{
    int n;
    
    ans = 100000;
    
    cin >> r >> n;
    
    while(n--) {
        cin >> a >> b;
        ans = min(ans, r - sqrt((a*a)+(b*b)) );
    }
    
    cout << fixed;
    cout << setprecision(8) << ans << endl;    
    return 0;
}
