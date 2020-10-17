#include <bits/stdc++.h>

using namespace std;

#define fs first
#define sd second
#define pb push_back
#define vii vector<int>
#define pii pair<int, int>
#define MAXN 120000

const int INF = 0x3f3f3f3f;

vector<int> aa;


int n, aux;

int solve(int a) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n - 1; ++j) {
            if(a == i) break;
            if(a == j || i == j) continue;
            // cout << aa[i] << ' ' << aa[j] << endl;
            if((aa[i] + aa[j]) == aa[a])
                return 1;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> aux;
        aa.pb(aux);
    }
    
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        ans = solve(i);
        if(ans) break;
    }

    if(ans) {
        cout << "SIM" << endl;
    } else {
        cout << "NAO" << endl;
    }

    return 0;
}