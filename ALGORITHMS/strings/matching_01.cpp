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

vector<int> naive_mathing(const string& s, const string &t) {
    const int sn = s.size();
    const int tn = t.size();
    vector<int> v;

    // s can't be in t
    if(sn > tn) {
        v.push_back(-1);
        return v;
    }

    int index;
    for(int i = 0; i < tn; ++i) {
        index = i;
        for(int j = 0; j < sn && index < tn; ++j) {
            if(s[j] == t[index]) {
                if(j == sn-1) {
                    v.push_back(i);
                    break;
                }
                ++index;
            } else {
                break;
            }
        }
    }

    if(v.empty()) {
        v.push_back(-1);
    }
    
    return v;
}

// t < s
// O(mn)
vector<int> naive_matching_kmp(const string& s, const string &t) {
    const int n = s.size();
    const int m = t.size();
    vector<int> v;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(i + j >= n || t[j] != s[i + j]) {
                v.push_back(0);
                break;
            } else {
                v.push_back(j);
            }
        }
    }
    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s, t;
    cin >> s >> t;

    vector<int> v = naive_mathing(s, t);

    for(auto i : v) {
        cout << i << ' ';
    } 
    cout << endl;
    return 0;
}