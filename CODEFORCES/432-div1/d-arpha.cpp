// problem: 432 div1 D arpha
// editorial: https://codeforces.com/blog/entry/54317

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

typedef long long ll;
 
const int MAXN = 2e6 + 10;
const int INF = 0x3f3f3f3f;

ll cnt[MAXN], 
   sum[MAXN],
   n, x, y, 
   i, j, k,
   num, p;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin>> n >> x >> y;

	for(i = 1;i <= n; ++i) {
		cin >> num;
		cnt[num] += 1;
		sum[num] += num;
	}

    // sum acumulate
	for(i = 1;i <= MAXN; ++i) {
		cnt[i] = cnt[i] + cnt[i-1]; 
		sum[i] = sum[i] + sum[i-1];
	}

	ll ans = n * x; // max answer  delete all numbers
	for(i = 2;i <= 1000000; ++i) { // for each gcd(a, b) = g

		ll cost = 0;
		for(j = i;j < MAXN && cost < ans;j += i) // for each interval [j, f), [f, j]
		{
			ll f = max(j - i + 1, j - (x/y));
			cost += (cnt[f-1] - cnt[j-i])*x + ((cnt[j] - cnt[f-1])*j - (sum[j]-sum[f-1]))*y; 
		}

		ans = min(ans, cost);
	}
	cout<< ans << endl;
	return 0;
}

