#include<bits/stdc++.h>

using namespace std;

int n, dp[1000][1000];
string final;

int solve(string& number, int nv, long long int rest) {

    if(nv == (int)number.size()) {
        // cout << "rest " << rest << endl;
        if(rest == 0) {
            final = number;
            return 1;
        } else return 0;
    }

    if(dp[nv][rest]!=-1)
        return dp[nv][rest];

    if(number[nv]=='?') {
        for(int i = 0; i <= 9; ++i) {
            if(nv == 0 && number[nv]=='?' && i == 0)  {
                continue;
            }
            number[nv] = (char)(i + '0');
            if(dp[nv][rest] = solve(number, nv + 1, ((10*rest)%n + (int)(number[nv]-'0'))%n))
                return 1;
            number[nv] = '?';
        }
    } else {
        if(dp[nv][rest] = solve(number, nv + 1, ((10*rest)%n + (int)(number[nv]-'0'))%n))
            return 1;
    }
    return 0;
}

int main() {
    string number;
    cin >> number;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    final = '*';
    solve(number, 0, 0);
    cout << final << endl;
    return 0;
}