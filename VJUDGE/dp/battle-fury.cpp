// problem
// https://vjudge.net/contest/376149#problem/A
// password: Simulado2
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
#define MAXN 200600

const int INF = 0x3f3f3f3f;

int p,
    q,
    n,
    dp[MAXN];

vector<int> hitMonter(vector<int> monsters, int index) {
    for(int i = 0; i < n; ++i) {
        if(i == index)
            monsters[i] -= p;
        else
            monsters[i] -= q;
    }
    return monsters;
}

int minimal_attack(vector<int> monsters) {

    int ans = INF, flag = 1;
    for(int i = 0; i < n; ++i) {
        if(monsters[i] > 0) {
            vector<int> aux = hitMonter(monsters, i);
            ans = min(ans, 1 + minimal_attack(aux));
            flag = 0;
        }
    }

    if(flag)
        return 0;

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> monsters(MAXN);

    cin >> n >> p >> q;
    for(int i = 0; i < n; ++i)
        cin >> monsters[i];
    cout << minimal_attack(monsters) << endl;

    return 0;
}