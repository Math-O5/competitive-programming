#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h> // memset
#include <algorithm> // lower_bound
#include <iomanip>
#include <bitset>
#include <unordered_map>
    // #include <bits/stdc++.h>

using namespace std;

#define fs first
#define sd second
#define pb push_back
#define vii vector<int>
#define pii pair<int, int>
#define MAXN 120000

const int INF = 0x3f3f3f3f;

int sum(vector<int>& bts, int index) {
    int sum = 0;
    while(index > 0) {
        sum += bts[index];
        index -= index&(-index);
    }
    return sum;
}

void update(vector<int>& bts, int index, int value) {
    int n = (int)bts.size();
    while(n > index) {
    bts[index] += 1;
        index += index&(-index);
    }
}

int query(vector<int>& bts, int l, int r) {
    return sum(bts, r) - sum(bts, l-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, y;
    cin >> y >> n;

    vector<int> pos(y+1), pos_copy(y+1), bts(y+1, 0), ans(n);
    vector<vector<int>> players(n);
    int a, b, j, placed, unlucky;

    pos[0] = 0;
    for(int i = 1; i <= y; ++i) {
        cin >> pos[i];
        pos_copy[i] = pos[i];
    }

    for(int i = 0; i < n; ++i) {
        cin >> a >> placed >> b;
        players[i].push_back(placed);
        players[i].push_back(a);
        players[i].push_back(b);       
        players[i].push_back(i);
    }
    
    sort(pos.begin(), pos.end());
    sort(players.begin(), players.end());
    
    int end = y + 1;
    for(int i = n-1; i >=0; --i) {

        while(y > 0 and pos[y] >= players[i][0]) {
            update(bts, y, pos[y]);
            --y;
        }

        if(players[i][0] <= pos_copy[players[i][1]])
            ans[players[i][3]] = 0;
        else {
            int l = sum(bts, players[i][1]);
            int r = sum(bts, players[i][1] + players[i][2]);
            ans[players[i][3]] = r - l;
        }
    }

    for(int i = 0; i < bts.size(); ++i)
        cout << bts[i] << ' ';
    cout << endl;

    for(int i = 0; i < n; ++i)
        cout << ans[i] << "\n";
        
    return 0;
}