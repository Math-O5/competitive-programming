// problem:
// https://codeforces.com/contest/1296/problem/E1
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    string s, ans;
    char a, b;
    cin >> n >> s;

    a = s[0];
    b = 'a';
    ans.push_back('0');

    for(int i = 1; i < (int)s.size(); ++i) {
        if(s[i] >= a) {
            a = s[i];
            ans.push_back('0');
        } else if(s[i] >= b) {
            b = s[i];
            ans.push_back('1');
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n" << ans << endl;
    return 0;
}