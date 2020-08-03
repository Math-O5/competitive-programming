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
const int max_alpha = 256;

// Input: zxcvbnmadfghjklqrtyuiop
// Output: abcdfghijklmnopqrtuvxyz
// O(n + 256)
// stable sorting
string counting_sort(string s) {
    int n = s.size();
    vector<int> count(max_alpha, 0);
    string output(s);
    
    for(int i = 0; i < n; ++i) {
        count[(int)s[i]]++;
    }
    for(int i = 1; i < max_alpha; ++i) {
        count[i] += count[i-1];
    }
    for(int i = 0; i < n; ++i) {
        output[count[(int)s[i]]-1] = s[i];
        count[(int)s[i]]--;
    }
    return output;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    cout << counting_sort(s) << endl;
    return 0;
}