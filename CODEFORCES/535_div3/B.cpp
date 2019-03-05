#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int x[n];
    for(int i = 0; i < n; ++i) cin >> x[i];
    sort(x, x+n);
    for(int i = n-1; i >= 0; --i) if((x[n-1] % x[i]!=0) || (x[i]==x[i-1])) {
        cout << x[n-1] << " " << x[i] << endl;
        break;
    }
    return 0;
}