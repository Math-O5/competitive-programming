// Problem 10543
// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1475

// LIS - Longest Increase Sequence
// https://en.wikipedia.org/wiki/Patience_sorting
// https://neps.academy/lesson/163
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
#define MAX 300000

const long long int INF = 0x3f3f3f3f;

long long int n, aux;
vector<long long int> topo;
vector<long long int> numbers;

// for i to m
// m < 10^5
// | ai | <= 10^9
// O m(m log m) = 10^5 * (10^5 * 5)
void lis(int dp[]) {
    topo.clear();
    topo.pb(numbers[0]);
    vector<long long int>::iterator it;

    for(long long int i = 0; i < n; ++i) {
        it = lower_bound(topo.begin(), topo.end(), numbers[i]);
        
        if(it == topo.end()) {
            topo.pb(numbers[i]);
        }
        else {
            *it = numbers[i];        
        }

        dp[i] = (long long int)topo.size();
    }

}

// O (n^2)
int cresc[MAX],
    desc[MAX];

// for i to m
// m < 10^5
// | ai | <= 10^9
// O m * m * m) = 10^5 * 10^5 * 10^5) = 10^15 /(O o O)
void lis_dp(int dp[]) {
    dp[0] = 1;
    for(int i = 1; i < n; ++i) {
         // the size of least increase sequence is 1
        dp[i] = 1;
        
        for(int j = 0; j < i; ++j) {
            if(numbers[i] > numbers[j]) {
                dp[i] = max(1 + dp[j], dp[i]);
            }
        }
    }
}

// m < 10^5
// | ai | <= 10^9
// O m(m log m) = 10^5 * (10^5 * 5)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    
    for(long long int i = 0; i < n; ++i) {
        cin >> aux;
        numbers.pb(aux);
    }   

    lis(cresc);
    reverse(numbers.begin(), numbers.end());
    lis(desc);
    reverse(desc, desc+n);

    int ans = 0;
    // check all subsets from i
    for(int i = 0; i < n; ++i) {
        ans = max(ans, (2*min(cresc[i], desc[i]) - 1));
    }
    cout << ans << endl;

    return 0;
}