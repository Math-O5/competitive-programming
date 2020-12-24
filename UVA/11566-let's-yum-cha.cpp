#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int n, x, t, k, dp[101][2000];

vector<int> favours[101];

int calc_mean(int cost, int i) {
    if(cost < 0)
        return -INF;

    if(cost == 0 || i == k) {
        return 0;
    }

    if(dp[i][cost] != 0)
        return dp[i][cost];

    int load = 0;
    for(int j = 1; j <= n + 1; ++j)
        load += favours[i][j];
    return dp[i][cost] = max(calc_mean(cost - favours[i][0], i + 1) + load,
                calc_mean(cost, i + 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while(cin >> n >> x >> t >> k, n > 0, x > 0, t > 0, k > 0) {
        double mean, cost;
        int aux;
        for(int i = 0; i < k; ++i) {
            for(int j = 0; j <= n + 1; ++j) {
                cin >> aux;
                favours[i].push_back(aux);
            }
        }
        cost = (double)(((n+1)*x) - t)*0.9;
        mean = (double)calc_mean(cost, 0);        
        cout << fixed;
        cout << setprecision(2) << mean/(double)(n+1) << endl;    
    }
    return 0;
}