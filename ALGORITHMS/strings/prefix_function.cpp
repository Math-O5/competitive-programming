// source: https://cp-algorithms-brasil.com/strings/prefixo.html
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


vector<int> lcp(const string& s) {
    const int n = s.size(); 
    vector<int> pi(n);
    pi[0] = 0;
    for(int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while(j > 0 && s[j] != s[i]) {
            j = pi[j-1];
        }

        if(s[i] == s[j]) {
            pi[i] = ++j;
        } else {
            pi[i] = j;
        }
    }

    return pi;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    vector<int> v = lcp(s);
    for(auto x : v) 
        cout << x << ' ';

    return 0;
}