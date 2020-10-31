/*
    Weighted Subset Sum Problem

    W is max capacity the pack support.

    Pick the maxxium subset of S less or equal than W:

    items : valor, pes

    Solution: 
        S is the set of items picked.
        w[i] is the weight of object i

        n not in S, so OPT(n) = OPT(n-1, W)
        n in S, so OPT(n-1, W - w[i])

    then dp: source: http://www.lcad.icmc.usp.br/~jbatista/scc210/ProgDin1.pdf

*/

#include <vector>
#include <iostream>

using namespace std;

int dp[420][220];
vector<pair<int, int>>items; 

int knapsack(int stand, int index) {
    if(dp[index][stand] >= 0) 
        return dp[index][stand];
    
    if(stand <= 0 || index == (int)items.size())
        return dp[index][stand] = 0;

    if(items[index].second > stand) {
        return dp[index][stand] = knapsack(stand, index + 1);
    } else {
        return dp[index][stand] = max(items[index].first + knapsack(stand - items[index].second, index + 1),
                                    knapsack(stand, index + 1));
    }
}

void print_Chosen_values(int stand, int index) {
    if(stand < 0 || index < 0)
        return;
        
    if(dp[index][stand] == dp[index][stand-1]) { // 
        print_Chosen_values(stand, index-1);
        return;
    } else {
        cout << index << ' ' << items[index].second << '\n';
        print_Chosen_values(stand - items[index].second, index-1);
         
    }

}

int knapsack_iterative(int stand, int index) {
    // the first row must be all zeros
    for(int i = 1; i <= (int)items.size(); ++i) {
        for(int peso = 0; peso <= stand; ++peso) {
            if(items[i].second > peso) {
                dp[i][peso] = dp[i-1][peso];
            } else {
                dp[i][peso] = max(dp[i-1][peso], items[i].first + dp[i-1][peso - items[i].second]);
            }
        }
    }

    return dp[(int)items.size()][stand];
}

int main() {

    return 0;
}