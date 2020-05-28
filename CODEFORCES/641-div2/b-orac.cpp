
/*
   problems: https://codeforces.com/contest/1350
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
#define MAXN 130000

const int INF = 0x3f3f3f3f;

int dp[MAXN], n, seqA[MAXN], seqB[MAXN];
  
int lis() {
    int ans = 1;

    for(int i = 1; i <= n; ++i) {
        for(int j = 2 * i; j <= n; j += i) {
            // if the last indexSeqA[i + 1] is divible by inexSeq[j] and can be added to lis 
            if( seqA[j - 1] > seqA[i - 1] && dp[j] < dp[i] + 1) {
                dp[j] = 1 + dp[i];
                ans = max(dp[j], ans);
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;

        for(int i = 0; i < n; ++i) {
            cin >> seqA[i];
            dp[i] = 1;
        }

        cout << lis() << '\n';
    }

    return 0;
}