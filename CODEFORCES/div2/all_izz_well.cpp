#include<iostream>
#include<string>
#include<vector>

using namespace std;

char maps[101][101];
int visited[101][101];
char word[] = "ALLIZZWELL";
int n, c;
int lastPos = 9;

int moves[8][2] = {1, 0,
                   0, 1,
                  -1, 0,
                   0, -1,
                   1, 1, 
                  -1, -1, 
                  -1, 1,
                   1, -1};

bool valid(int i, int j) {
    return (i >= 0 && j >= 0 && i < n && j < c);
}

int solve(int i, int j, int pos, int vis) {
    // cout << "i: " << i << " j> " << j << ' ' <<  pos  << ' ' << maps[i][j] << ' ' << word[pos] << endl;
    visited[i][j] = vis;
    
    if(maps[i][j] != word[pos])
        return 0;
    if(maps[i][j] == word[pos] && pos == lastPos) 
        return 1;
    
    for(int k = 0; k < 8; ++k) {
        int l = i+moves[k][0], r = j+moves[k][1]; 
        if(valid(l, r) && visited[l][r] != vis && maps[l][r]==word[pos+1]) {
            int ans = solve(l, r, pos + 1, vis);
            visited[l][r] = 0;
            if(ans) 
                return 1;
        }
    }

    return 0;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> c;
        vector<pair<int, int>> as;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < c; ++j) {
                cin >> maps[i][j];
                if(maps[i][j] == 'A') {
                    as.push_back(make_pair(i, j));
                }
            }
        }

        int flag = 0;
        for(int i = 0; i < as.size(); ++i) {
            flag = solve(as[i].first, as[i].second, 0, i + 1); 
            if(flag) break;
        }

        if(flag) {
            cout << "YES\n";
        } else cout << "NO\n";

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < c; ++j) {
                visited[i][j] = 0;
            }
        }
    }

    return 0;
}