// Source: https://cp-algorithms.com/string/string-hashing.html
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

// p must be 2^k and more that the possibilities of caracteres.
int hash_string(string s) {
    const long long int m = 1e9;
    int hash = 0;
    int pow = 1;
    int p = 31;
    for(int i = 0; i < s.size(); ++i) {
        hash = (hash + (s[i] - 'a' + 1)*pow) % m;
        pow = (pow*p) % m; 
    }

    return hash;
}

// Search for duplicate strings in an array of strings
// the string should be less than m
// The follow function return no repeat strings
vector<string> eliminate_duplicade(vector<string> group) {
    vector<string> new_group;
    vector<pair<long long, int>> hashes(group.size());

    for(int i = 0; i < group.size(); ++i) {
        hashes[i] = {hash_string(group[i]), i};
    }   

    sort(hashes.begin(), hashes.end());

    new_group.push_back(group[hashes[0].second]);
    for(int i = 1; i < group.size(); ++i) {
        if(hashes[i].first != hashes[i-1].first) {
           new_group.push_back(group[hashes[i].second]); 
        }
    }
    return new_group;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    string s;
    vector<string> g;
    cin >> n;
    while(n--) {
        cin >> s;
        g.push_back(s);
    }

   vector<string> c = eliminate_duplicade(g);

    for(int i = 0; i < c.size(); ++i) {
        cout << c[i] << endl;
    }

    c.clear();
    return 0;
}