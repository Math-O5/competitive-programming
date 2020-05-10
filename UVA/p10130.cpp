#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

vector<pair<int, int>> prod;
int dp[1010][150]; // value and i

int knapsack(int stand, int produto) {
    if(dp[produto][stand] >= 0) 
        return dp[produto][stand];
    
    if(stand <= 0 || produto == (int)prod.size())
        return dp[produto][stand] = 0;

    if(prod[produto].second > stand) {
        return dp[produto][stand] = knapsack(stand, produto + 1);
    } else {
        return dp[produto][stand] = max(prod[produto].first + knapsack(stand - prod[produto].second, produto + 1),
                                    knapsack(stand, produto + 1));
    }
}

int knapsack_iterative(int stand, int produto) {
    // the first row must be all zeros
    for(int i = 1; i <= (int)prod.size(); ++i) {
        for(int peso = 0; peso <= stand; ++peso) {
            if(prod[i].second > peso) {
                dp[i][peso] = dp[i-1][peso];
            } else {
                dp[i][peso] = max(dp[i-1][peso], prod[i].first + dp[i-1][peso - prod[i].second]);
            }
        }
    }

    return dp[(int)prod.size()][stand];
}

int main()
{
    int t, n, g, a, b, valor;
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    while(t--) {
        
        valor = 0;
        memset(dp, -1, sizeof(dp));
        
        cin >> n;
        for(int i = 0; i < n; ++i) {
            cin >> a >> b;
            prod.push_back(make_pair(a, b));
        }
        
        cin >> g;
        for(int i = 0; i < g; ++i) {
            cin >> a;
            valor += knapsack(a, 0);
        }
        cout << valor << '\n';
        prod.clear();
    }

    return 0;
}
