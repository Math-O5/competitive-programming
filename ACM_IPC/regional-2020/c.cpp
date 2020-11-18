#include<bits/stdc++.h>

#define MAXN 1000040

using namespace std;

map<string, int> found;
int pecA[MAXN], pecB[MAXN];
string a[100010], b[100010];
int ff[MAXN][2];
map<string,int>::iterator it;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n; ++i) {
        cin >> a[i];
    }

    for(int i = 0 ; i < m; ++i) {
        cin >> b[i];
    }
    int t = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            string concat = a[i] + b[j];
            // int test = found[concat];
            it = found.find(concat);
            if(it == found.end()) {
                // found[concat] = t;
                found.insert(make_pair(concat, t));
                ff[t][0] = i;
                ff[t][1] = j; 
                ++t;
            } else {
                pecA[i] = 1;
                pecB[j] = 1;
                pecA[ff[it->second][0]] = 1;
                pecB[ff[it->second][1]] = 1;
            }
        }
    }
    int ans1= 0, ans2= 0;
    for(int i = 0; i < n; ++i) {
        if(pecA[i] == 0)
            ++ans1;
    }
    for(int i = 0; i < m; ++i) {
        if(pecB[i] == 0)
            ++ans2;
    }
    cout << ans1 << ' ' << ans2 << '\n';
    return 0;
}