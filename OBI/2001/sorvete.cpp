#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h> // memset
#include <algorithm> // lower_bound
#include <iomanip>
    // #include <bits/stdc++.h>

using namespace std;

#define fs first
#define sd second
#define pb push_back
#define vii vector<int>
#define pii pair<int, int>
#define MAXN 120000

const int INF = 0x3f3f3f3f;


bool comp(pair<int, int> a, pair<int, int> b) {
    if(a.fs < b.fs || (a.fs == b.fs && a.sd <= b.sd)) {
        return true;
    } else return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<pair<int, int>> inter;
    int n, t, a, b;

    cin >> n >> t;
    for(int i = 0; i < t; ++i) {
        cin >> a >> b;
        inter.pb(make_pair(a, b));
    }

   sort(inter.begin(), inter.end(), comp);

    for(int i = 0; i < t; ++i) {
        cout << inter[i].fs << ' ';

        int final = inter[i].sd;
        while(i < t - 1) {
            if(final >= inter[i + 1].fs) {
                final = max(final, inter[i + 1].sd);
                ++i;
            } else break;
        }

        cout << final << endl;
    }
    return 0;
}