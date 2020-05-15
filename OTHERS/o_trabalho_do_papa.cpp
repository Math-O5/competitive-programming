#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

#define peso first
#define res second

const int INF = 0x3f3f3f3f;
vector<pair<int, int>> caixas;
int N, a, b, dp[2002][2002];

bool mySort(pair<int, int> a, pair<int, int> b) {
    return (a.res > b.res);
}

void Print() {
    for(int i = 0; i < (int)caixas.size(); ++i) {
        cout << caixas[i].res << ' ' << caixas[i].peso << '\n';
    }
}

int knap() {
    
    memset(dp, -1, sizeof dp);
    
    for(int i = 0; i <= N; ++i) {
        dp[0][i] = INF;
    }
    
    // Print();
    
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            // OPT(i, j) = max( pegar caixa anterior, pegar essa caixa )
            dp[i][j] = max(dp[i][j-1], min(dp[i-1][j-1], caixas[j-1].res) - caixas[j-1].peso);
            ans = (dp[i][j] > -1)? i : ans;
        }
    }
    return ans;
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> a >> b;
        caixas.push_back(make_pair(a, b));
    }
    
    sort(caixas.begin(), caixas.end(),mySort);
    
    cout << knap() << '\n';

    return 0;
}
