/*
    Longest Commum sequence in between two sequences
    O (m * n)
    source: https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem

    input:  n, m and the sequences
            4 4
            1 2 3 4
            3 2 1 4
    output: the length of commum sequence 
            2
*/ 
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h> // memset
#include <algorithm> // lower_bound

using namespace std;

#define fs first
#define sd second
#define pb push_back
#define MAXN 1200

const int INF = 0x3f3f3f3f;

int dp[MAXN][MAXN],
    seqA[MAXN],
    seqB[MAXN];

int lcs(int x, int y) {
    if(x == -1 || y == -1)  {
        return 0;
    }

    if(dp[x][y] != -1) {
        return dp[x][y];
    }

    if(seqA[x] == seqB[y]) 
        return dp[x][y] = 1 + lcs(x- 1, y - 1);

    return dp[x][y] = max(lcs(x - 1, y), lcs(x, y - 1));
}

int lcs_iterative(int n, int m) { 
      
    for(int i = 0; i <= n; ++i) {  
        for(int j = 0; j <= m; ++j) {  
            if(i == 0 || j == 0)  
                dp[i][j] = 0;  
      
        else if(seqA[i - 1] == seqB[j - 1])  
            dp[i][j] = 1 + dp[i - 1][j - 1];  
      
        else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  
        }  
    }  
          
    return dp[n][m];  
}  
  

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; // n is size of seqA and m is size of seqB
    cin >> n >> m;

    for(int i = 0; i < n; ++i) {
        cin >> seqA[i];
    }

    for(int i = 0; i < m; ++i) {
        cin >> seqB[i];
    }

    // no value has been calculate, -1 indicate it.
    memset(dp, -1, sizeof dp);

    cout << lcs(n - 1, m - 1) << '\n';

    return 0;
}