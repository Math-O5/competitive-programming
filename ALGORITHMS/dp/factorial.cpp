#include<bits/stdc++.h>

using namespace std;

#define MAXN 100000

int dp[MAXN], n;

void bottom_up() {
    dp[0] = 1;
    for(int i = 1; i < n; ++i) {
        dp[i] = dp[i-1] * i;
    }
}

int top_down(int x) {
    if(x == 0)
        return 1;

    if(dp[x] != 0) 
        return dp[x];

    return dp[x] = x * top_down(x-1);
}

int main() {

    n = 10;

    cout << dp[n-1] << endl;
    return 0;
}