#include<bits/stdc++.h>

using namespace std;

int n, k, x, y;
vector<vector<pair<int, int>>> tiles;

void reflet_x(vector<pair<int, int>>& tile) {
    for(int i = 0; i < (int)tile.size(); ++i) 
        tile[i].first = - tile[i].first; 
}

void reflet_y(vector<pair<int, int>>& tile) {
    for(int i = 0; i < (int)tile.size(); ++i) 
        tile[i].second = - tile[i].second; 
}

double solve() {

}

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        vector<pair<int, int>> tile;

        cin >> k;
        for(int j = 0; j < k; ++j) {
            cin >> x >> y;
            tile.push_back(make_pair(x, y));
        }
        tiles.push_back(tile);
    }

    cout << solve() << endl;

    return 0;
}