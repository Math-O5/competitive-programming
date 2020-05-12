// Hint from: https://codeforces.com/blog/entry/74777
// Problem https://atcoder.jp/contests/dp/tasks/dp_e
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
vector<int> weights(101, INF), values(101, INF); 
vector<int> dp (1e5+1, INF);
int n, w, sum;

// int knapsack2_recursivo(int value, int i) {
//     int nao_pega; 
//     int pega;

//     if(n -1 == i) {
//         nao_pega = INF;
//         pega = weights[i];
//     } else {
//         nao_pega = knapsack2_recursivo(value, i + 1);
//         pega = weights[i] + knapsack2_recursivo(value + values[i], i + 1);
//     }

//     return dp[value] = min(pega, nao_pega);
// }

void knapsack2() {

    dp[0] = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = sum - values[i]; j >= 0; --j) {
            dp[j + values[i]] = min(dp[j + values[i]], weights[i] + dp[j]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
  
    cin >> n >> w;
    for(int i = 0; i < n; ++i) {
        cin >> weights[i] >> values[i];
        sum += values[i];
    }

    knapsack2();
    //knapsack_recursivo(0, 0);

    // imprimir resposta
    int i = sum;
    while(i >= 0 && (dp[i] > w)) {
        --i;
    }

    cout << ((i >= 0)? i : 0) << '\n';

    return 0;
}
