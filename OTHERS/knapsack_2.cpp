// Hint from: https://codeforces.com/blog/entry/74777
// Problem https://atcoder.jp/contests/dp/tasks/dp_e
/*
    A singularidade deste problema é o o espaço que o "peso" pode assumir,
    chegando a 10^9, portanto um array não comporta a solução. Por isso é feita uma variação
    do knapsack em que em vez de maximizar o valor dos itens, procura-se como minizar o peso
    para obter um dado valor.  

    N < 100           (e2)
    Valor < 1000      (e3)
    peso < 1000000000 (e9)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
vector<int> weights(101, INF), values(101, INF); 
vector<int> dp (1e5+1, INF);
int n, w, sum;

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

    // imprimir resposta
    int i = sum;
    while(i >= 0 && (dp[i] > w)) {
        --i;
    }

    cout << ((i >= 0)? i : 0) << '\n';

    return 0;
}
