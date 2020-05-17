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
#define MAXN 120000

const int INF = 0x3f3f3f3f;

int dp[MAXN], n, aux;
vector<int> coins;

// input:
// 4 7
// 1 3 4 5
// output: 2

// 2 10
// 1 5 
// output: 2

// 2 10
// 3 3 
// output: INF 

// return 
//          x :the min number of coins to form the value
//         INF: It's not possible form the value
// complexity O(n*value);
int change(int value, int i) {
    if(value == 0)
        return 0;
    if(value < 0 || i >= n)
        return INF;

    if(dp[value] != -1) {
        return dp[value];
    }

    return dp[value] = min(1 + change(value - coins[i], i), change(value, i + 1));
}

// return 
//          x :the min number of coins to form the value
//         INF: It's not possible form the value
// complexity O(n*value);
int change_2(int value) {
    if(value == 0)
        return 0;

    if(value < 0)
        return INF;

    if(dp[value] != -1) {
        return dp[value];
    }

    int ans = INF;
    for(int i = 0; i < n; ++i) {
        ans = min(change_2(value - coins[i]), ans);
    }

    return dp[value] = ans + 1;
}

// return:
//          1 : it is possible form the value with the coins
//          0 : it is not posible form the value the coins
int change_3(int value) {
    if(value == 0)
        return 1;
    if(value < 0)
        return 0;
    if(dp[value] != -1)
        return dp[value];

    for(int i = 0; i < n; ++i) {
        if(change_3(value - coins[i])) {
            dp[value] = 1;
            return dp[value];
        }
    }

    return dp[value] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int value;
    memset(dp, -1, sizeof dp);

    cin >> n >> value;
    for(int i = 0; i < n; ++i) {
        cin >> aux;
        coins.pb(aux);
    }

    cout << change(value, 0) << endl;
    memset(dp, -1, sizeof dp);
    cout << change_2(value) << endl;
    memset(dp, -1, sizeof dp);
    cout << change_3(value) << endl;

    return 0;
}