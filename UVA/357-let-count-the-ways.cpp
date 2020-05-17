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

const long long int INF = 0x3f3f3f3f;

long long int coins[] = {1, 5, 10, 25, 50}, 
    dp[MAXN][5];


long long int change_2(long long int value, long long int i) {
    if(value < 0 || i == 5)
        return 0;
    
    if(value == 0)
        return 1;

    if(dp[value][i] != -1)
       return dp[value][i];
  
    return dp[value][i] = change_2(value - coins[i], i) + change_2(value, i + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(dp, -1, sizeof dp);
    long long int n;
    while(cin >> n) {
        long long int ans = change_2(n, 0);
        if(ans != 1) {
            cout << "There are " << ans << " ways to produce " << n << " cents change.\n";
        } else {
            cout << "There is only " << 1 << " way to produce " << n << " cents change.\n";
        }
    }
    return 0;
}