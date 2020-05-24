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
    seqB[MAXN],
    score[5][5] = {
                    {0, 5, 5, 5, 3},
                    {5, 0, 4, 5, 3},
                    {5, 4, 0, 5, 3},
                    {5, 5, 5, 0, 3},
                    {3, 3, 3, 3, INF},
                };

int lcs(int x, int y) {
    if(x == 0 || y == 0)  {
        return score[seqA[x]][seqB[y]];
    }

    if(dp[x][y] != -1) {
        return dp[x][y];
    }

    if(seqA[x] == seqB[y]) 
        return dp[x][y] = lcs(x- 1, y - 1);

    return dp[x][y] = min(lcs(x - 1, y), lcs(x, y - 1));
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