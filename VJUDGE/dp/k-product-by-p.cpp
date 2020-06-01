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
#define MAXN 200105

const int INF = 0x3f3f3f3f;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
    int n, t, p, k, aux;
    int sum[MAXN], prod[MAXN], value;
    cin >> t;
    while(--t >= 0) {
        cin >> n >> p >> k;
        value = 0;

        for(int i = 1; i <= n; ++i) {
            cin >> prod[i];
        }

        prod[0] = 0;
        sum[0] = 0;
        sort(prod, prod + n + 1);

        //cumulative
        for(int i = 1; i <= k; ++i) {
            sum[i] = sum[i-1] + prod[i];
            if(sum[i] <= p) {
                value = i;
            }
        }

        for(int i = k; i <= n; ++i) {
            sum[i] = prod[i] + sum[i - k];
            if(sum[i] <= p) {
                value = i;
            }
        }

        cout << value << endl;
    }
    return 0;
}