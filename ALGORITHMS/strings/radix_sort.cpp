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

int ith_digit(int num, int e) {
    return (num/e)%10;
}

// Input: zxcvbnmadfghjklqrtyuiop
// Output: abcdfghijklmnopqrtuvxyz
// O(n + 256)
// stable sorting
string counting_sort(string s, int e) {
    int n = s.size();
    vector<int> count(10, 0);
    string output(s);
    
    for(int i = 0; i < n; ++i) {
        count[ith_digit((int)s[i], e)]++;
    }
    for(int i = 1; i < 10; ++i) {
        count[i] += count[i-1];
    }
    for(int i = n-1; i >= 0; --i) {
        output[count[ith_digit((int)s[i], e)]-1] = s[i];
        count[ith_digit((int)s[i], e)]--;
    }
    return output;
}

int get_max(string s) {
    int ans = 0;
    for(auto i : s) {
        ans = max(ans, (int)i);
    }
    return ans;
}

string radix_sort(string s) {
    int maxn = get_max(s);

    for(int e = 1; maxn/e > 0; e *= 10) {
        s = counting_sort(s, e);
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    cout << radix_sort(s) << endl;
    return 0;
}