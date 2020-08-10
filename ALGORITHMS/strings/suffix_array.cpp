#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h> // memset
#include <algorithm> // lower_bound
#include <iomanip>
#include <bitset>
    // #include <bits/stdc++.h>

using namespace std;

#define fs first
#define sd second
#define pb push_back
#define vii vector<int>
#define pii pair<int, int>
#define MAXN 120000

const int INF = 0x3f3f3f3f;

vector<int> sort_sufix_string(string const& s) {
    const int max_alpha = 256;
    int n = s.size();
    vector<int> p(n), c(n), count(max_alpha, 0);
    
    // Frequency array
    for(int i = 0; i < n; ++i) {
        count[(int)s[i]]++;
    }

    // Prefix array
    for(int i = 1; i < max_alpha; ++i) {
        count[i] += count[i-1];
    }

    // Attr the position ordered P
    for(int i = 0; i < n; ++i) {
        p[count[(int)s[i]]-1] = i;
        count[(int)s[i]]--;
    }

    // Attr classes C
    c[p[0]] = 0;
    int cl = 1;
    for(int i = 0; i < n; ++i) {
        if(s[p[i]] != s[p[i-1]]) {
            cl++;
        }
        c[p[i]] = cl-1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    return 0;
}