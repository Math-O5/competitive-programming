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

map<int, int> dp;

void solve(int n) {
    int aux;
    vector<int> nums;
    for(int i = 0; i < n; ++i) {
        // dp[i] = 1;
        cin >> aux;
        nums.pb(aux);
    }

    int max_dp = 1, max_n = nums[0], max_i = 0;
    for(int i = 0; i < n; ++i) {
        dp[nums[i]] = dp[nums[i]-1] + 1;
        
        if(dp[nums[i]] >= max_dp) {
            max_dp = dp[nums[i]];
            max_i = i;
            max_n = nums[i];
        }
    }

    // for(int i = 1; i < n; ++i) {
    //     for(int j = 0; j < i; ++j) {
    //         // update max subsequence
    //         if(nums[i] == nums[j] + 1)
    //             dp[i] = max(dp[i], dp[j]+1);
                    
    //         if(nums[i] == nums[j] + 1) {
    //             if(dp[i] > max_dp) {
    //                 max_dp = dp[i];
    //                 max_i = i;
    //                 max_n = nums[i];
    //             }
    //         }
    //     }
    // }

    cout << max_dp << endl;
    vector<int> ans;
    for(int i = n - 1; i >= 0; --i) {
        if(nums[i]==max_n) {
            ans.pb(i+1);
            --max_n;
        }
    }

    for(int i = ans.size()-1; i >= 0; --i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    solve(n);
    return 0;
}