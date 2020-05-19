// problem:
// https://s3-us-west-2.amazonaws.com/prod-runcodes-files/exercisefiles/14551/p357.pdf?X-Amz-Content-Sha256=e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855&X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAI3OUHGVPPSQMGO5Q%2F20200517%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20200517T161409Z&X-Amz-SignedHeaders=Host&X-Amz-Expires=120&X-Amz-Signature=34906f6b50e7356f85fcc8f321941df9d8077f1b828c1327f2d0cc19c24d9dbb
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
#define MAXN 30001

const int INF = 0x3f3f3f3f;

int coins[] = {2, 5, 10, 20, 50, 100}, 
    dp[MAXN];


int change_knapsack(int mark[], int value, int i) {
    dp[0] = 1;
    for(int i = 0; i < 6; ++i) {
        for(int j = value; j >= 2; --j) {
            for(int k = 1; k <= mark[i] && j - k*coins[i] >= 0; ++k)
                dp[j] += dp[j - k*coins[i]];
        }
    }

    return dp[value];
}

int change_knapsack2(int value, int i) {
    dp[0] = 1;
    for(int i = 0; i < 6; ++i) {
        for(int j = value; j >= 2; --j) {
            for(int k = 1; j - k*coins[i] >= 0; ++k)
                dp[j] += dp[j - k*coins[i]];
        }
    }

    return dp[value];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int mark[6];
    int s;
    
    cin >> s;
    for(int i = 0; i < 6; ++i) {
        cin >> mark[i];
    }
    cout << change_knapsack(mark, s, 0) << '\n';
    return 0;
}