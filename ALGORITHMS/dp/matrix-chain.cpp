#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h> // memset
#include <algorithm> // lower_bound
#include <iomanip>
#include <bitset>
#include <stack>
    // #include <bits/stdc++.h>

using namespace std;

#define fs first
#define sd second
#define pb push_back
#define vii vector<int>
#define pii pair<int, int>
#define MAXN 26

const int INF = 0x3f3f3f3f;

int min_chain_multiplication(vector<int> d) {
    int n = (int)d.size();
    int dp[MAXN][MAXN];

    for(int l = 0; l < n; ++l) {
        int i = 1;
        int j = l + 1;
        while(j <= n) {
            if(i == j) {
                dp[i][j] = 0;
            } else {
                int mini = INF;
                for(int k = i; k <= j; ++k) {
                    mini = min(mini, dp[i][k] + dp[k+1][j] + (d[i-1]*d[k]*d[j]));
                }
                dp[i][j] = mini;
            }

            ++i; ++j;
        }
    }
    return dp[n][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, a, b;
    char m;

  
    return 0;
}