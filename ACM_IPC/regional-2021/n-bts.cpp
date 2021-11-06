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


/*
    1 - Save all queries (players) and sort by the last positined teams
    2 - Create an empty array of size MAXN+1 (BTS)
    3 - Save slots attached with the year it belongs (EX: [3 2 1] save as [(3,1), (2,2), (1,3)])
    4 - Sort the array of slots by the number of slots (attached with the year it belongs)
    5 - Start answering the queries for the lastest positined teams -> add to BTS all slots bigger than their score, 
    BUT keep the origial index in the array BTS.
    6 - For each querie, return the sum in the range asked.

*/

/*
    Return: the sum in range [0, index] (from zero up to the index)
*/
int sum(vector<int>& bts, int index) {
    int sum = 0;
    while(index > 0) {
        sum += bts[index];
        index -= index&(-index);
    }
    return sum;
}

/*
    Build and update BTS
*/
void update(vector<int>& bts, int index, int value) {
    int n = (int)bts.size();
    while(n > index) {
    bts[index] += value;
        index += index&(-index);
    }
}

/*
    Return: The sum in range (l, r]
*/
int query(vector<int>& bts, int l, int r) {
    return sum(bts, r) - sum(bts, l-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, y;
    cin >> y >> n;

    vector<vector<int>> pos(y+1);
    vector<int> pos_copy(y+1), bts(y+1, 0), ans(n);
    vector<vector<int>> players(n);
    int a, b, j, placed, unlucky;

    pos[0].push_back(0);
    pos[0].push_back(0);
    for(int i = 1; i <= y; ++i) {
        cin >> a;
        pos[i].push_back(a);
        pos[i].push_back(i);
        pos_copy[i] = pos[i][0];
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

        while(y > 0 and pos[y][0] >= players[i][0]) {
            update(bts, pos[y][1], 1);
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

    // Show BTS
    // for(int i = 0; i < bts.size(); ++i)
    //     cout << bts[i] << ' ';
    // cout << endl;

    for(int i = 0; i < n; ++i)
        cout << ans[i] << "\n";
        
    return 0;
}