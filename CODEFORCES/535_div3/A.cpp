#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, l1, r1, l2, r2;
    int ans1, ans2;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> l1 >> r1 >> l2 >> r2;
        if(l1 != l2) r2 = l2; 
        cout << l1 << ' ' << r2 << endl;
    }

    return 0;
}