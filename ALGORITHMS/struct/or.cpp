/**
 * You must say the longest number form such that:
 * The max value OR between al elements on the vector
 * 
 * [6] = 6
 * [6, 15] = 15
 *  ...
 * 
 * problem:
 * https://neps.academy/lesson/249
 */
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h> // memset
#include <algorithm> // lower_bound
#include <iomanip>

using namespace std;

#define fs first
#define sd second
#define pb push_back
#define vii vector<int>
#define pii pair<int, int>
#define MAXN 120000

const int INF = 0x3f3f3f3f;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, a, ans;
    cin >> n;

    ans = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a;
        ans |= a;
    }

    cout << ans << endl;
    return 0;
}