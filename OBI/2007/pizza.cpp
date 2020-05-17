// problem:
// https://olimpiada.ic.unicamp.br/pratique/p2/2007/f2/pizza/
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, a;
    cin >> n;
    vector<int> fatias(2*n+1);

    int sum = 0, ans = 0, ini = 0, fim = 0, newi = 0;
    for(int i = 0; i < n; ++i) {
        cin >> fatias[i];
    }

    for(int i = 0; i < n; ++i) {
        
        sum += fatias[i];
        ans = max(sum , ans)

    }
    cout << ans << endl;
    return 0;
}