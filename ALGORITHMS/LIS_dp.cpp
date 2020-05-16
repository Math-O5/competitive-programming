// LIS - Longest Increase Sequence
// http://www.lcad.icmc.usp.br/~jbatista/scc218/ProgDin2_novo.pdf
// input: 
// 8
// -7 10 9 2 3 8 8 1

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h> // memset

using namespace std;

#define fs first
#define sd second
#define pb push_back
#define MAX 100030 // max array

const int INF = 0x3f3f3f3f;

int n, aux, dp[MAX];
vector<int> numbers;

// O (n^2)
int lis(int num, int i) {
    if(i >= n - 2)
        return 0;
    if(num < numbers[i + 1]) {
        return max(1 + lis(numbers[i + 1], i + 1), lis(num, i + 1));
    }

    return lis(num, i + 1);
}

int lis_dp(int i) {

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    memset(dp, -1, sizeof dp);
    
    for(int i = 0; i < n; ++i) {
        cin >> aux;
        numbers.pb(aux);
    }

    int ans = 0;
    ans = lis(-INF, -1);
   
    
    cout << ans << '\n';

    return 0;
}