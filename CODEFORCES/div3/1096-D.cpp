#include<bits/stdc++.h>

using namespace std;

#define MAXN 1000000
const long long INF = 1e18;

int num[MAXN];
long long dp[MAXN][5];
string cmp = "hard";

int main() {
    int n;
    string s;
    cin >> n >> s;

    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j < 5; ++j)
            dp[i][j] = INF;
    }

    for(int i = 0; i < n; ++i) {
        cin >> num[i];
    }

    dp[0][0] = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 4; ++j) {
            if(cmp[j]!=s[i]) {
                dp[i+1][j] = min(dp[i][j], dp[i+1][j]);
            } else {
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]+num[i]);
            }
        }
    }

    long long minn = INF;
    for(int i = 0; i < 4; ++i) 
        minn = min(minn, dp[n][i]);
    cout << minn << endl;
    return 0;
}