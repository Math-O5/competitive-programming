#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

#define peso first
#define value second

const int INF = 0x3f3f3f3f;
int n, m, a, b, dp[1080][1080];
vector<pair<int, int>> carta;

int knapsack() {
    for(int i = 1; i <= m; ++i) {
        for(int j = 0; j <= n; ++j) {
            if(carta[i-1].peso > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], 
                               dp[i-1][j - carta[i-1].peso] + carta[i-1].value);
            }
        }
    }     
    
    return dp[m][n];
}

int main() {
    int j = 0;
    while((cin >> n >> m), n > 0 && m > 0) {
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < m; ++i) {
            cin >> a >> b;
            carta.push_back(make_pair(a, b));
        }
        
        cout << "Teste "<< ++j << '\n';
        cout << knapsack() << '\n';
        carta.clear();
    }

    return 0;
}
