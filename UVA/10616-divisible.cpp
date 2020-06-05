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
    #define MAXN 1200

    const long long int INF = 0x3f3f3f3f;

    long long int numbers[MAXN],
        dp[250][25][25], 
        n, q, d ,m;

    long long int backtracking(long long int index, long long int cnt, long long int sum) {

        if(cnt == m && sum % d == 0)
            return 1;

        if(index == n || cnt >= m) 
            return 0;
        

        if(dp[index][cnt][sum] != -1) {
            return dp[index][cnt][sum];
        }

        long long int nextSum = ( (sum + numbers[index]) % d);
        if(nextSum < 0)
            nextSum += d;

        return dp[index][cnt][sum] = backtracking(index + 1, cnt + 1, nextSum) +
                                    backtracking(index + 1, cnt, sum);

    }

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        long long int j = 0;
        while(cin >> n >> q, n > 0 && q > 0) {

            for(long long int i = 0; i < n; ++i) {
                cin >> numbers[i]; 
            }

            cout << "SET "<< ++j << ":" << endl;
            for(long long int i = 0; i < q; ++i) {
                memset(dp, -1, sizeof(dp));
                cin >> d >> m;
                cout << "QUERY " << i + 1 << ": " << backtracking(0, 0, 0) << endl;
            }
        }

        return 0;
    }