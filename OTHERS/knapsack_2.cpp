// Hint from: https://codeforces.com/blog/entry/74777
// Problem https://atcoder.jp/contests/dp/tasks/dp_e
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
vector<int> weights(101, INF), values(101, INF); 

void knapsack2() {
    int n, w, sum = 0;
    cin >> n >> w;

    vector<int> dp (1e5+1, INF);

    for(int i = 0; i < n; ++i) {
        cin >> weights[i] >> values[i];
        sum += values[i];
    }

    dp[0] = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = sum - values[i]; j >= 0; --j) {
            dp[j + values[i]] = min(dp[j + values[i]], weights[i] + dp[j]);
        }
    }

    int i = sum;
    while(i >= 0 && dp[i] > w) {
        --i;
    }

    cout << (i >= 0)? i : 0 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    knapsack2();
    return 0;
}
