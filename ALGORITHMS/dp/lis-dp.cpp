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

// O (n^2)
int lis_dp() {
    int ans = 0;
    
    dp[0] = 1;
    for(int i = 1; i < n; ++i) {
         // the size of least increase sequence is 1
        dp[i] = 1;
        
        for(int j = 0; j < i; ++j) {
            if(numbers[i] > numbers[j]) {
                dp[i] = max(1 + dp[j], dp[i]);
                ans = max(ans, dp[i]);
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    for(int i = 0; i < n; ++i) {
        cin >> aux;
        numbers.pb(aux);
    }


   
    cout << lis_dp() << '\n';
    cout << lis(-INF, -1) << '\n';

    return 0;
}