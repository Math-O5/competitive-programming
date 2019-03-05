#include <bits/stdc++.h>
using namespace std;
set <int> S;
pair<set<int>::iterator, bool> ret;
int ans;
int main()
{
    int n, m;
    cin >> n;
    while(n--) {
        cin >> m;
        ret = S.insert(m);
        if(ret.second) ans += 2;
        else S.erase(m);
    }
    cout << ans << endl;
  return 0;
}
