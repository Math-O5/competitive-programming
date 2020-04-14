#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
typedef long long int lli;
using namespace std;

vector<lli> c;
int main()
{
    lli n, a, b, ans = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a >> b;
        ans += ((b*n)-a);
        c.push_back(a - b);
    }
    sort(c.rbegin(),c.rend());
    for(lli i = 1; i <= n; ++i) {
        ans += i*c[i-1];
    }
    cout << ans << '\n';
    return 0;
}