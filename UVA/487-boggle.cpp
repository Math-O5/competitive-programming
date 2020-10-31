#include <bits/stdc++.h>

#define MAXN 100

using namespace std;

string table[MAXN];
int vis[MAXN][MAXN], t, n, l, c; // cases n, lines and column
// vector<string> words;

struct custom_compare final
{
    bool operator() (const string& a, const string& b) {
        if(a.size() == b.size()) {
            return a < b;
        } 
        return (a.size() < b.size());
    }
};

set<string, custom_compare> words;
int moves[8][2] = {  1, 0,
                     0, 1, 
                     1, 1,
                    -1, 0,
                    -1, 1,
                     1, -1,
                     0, -1,
                    -1, -1};

bool valid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

void dfs(int x, int y, string word) {
    
    vis[x][y] = 1;
// cout << "test> " << word << endl;
    
    if(!word.empty()) {
        if(word[word.size()-1] < table[x][y]) {
            word.push_back(table[x][y]);
        } else return;
    } else {
        word.push_back(table[x][y]);
    }
    
    if(word.size() >= 3) {
        words.insert(word);
    }


    for(int i = 0; i < 8; ++i) {
        int tmp_x = x + moves[i][0];
        int tmp_y = y + moves[i][1];

        if(valid(tmp_x, tmp_y) && vis[tmp_x][tmp_y] != 1) {
            dfs(tmp_x, tmp_y, word);
            vis[tmp_x][tmp_y] = 0;
        }
    }
}

bool mySort(const string& a, const string& b) {
    if(a.size() == b.size()) {
        return a < b;
    } 
    return (a.size() < b.size());
}

int main()
{
    cin >> t;
    while(t--) {
        getchar();
        cin >> n;
        for(int i = 0; i < n; ++i) {
            cin >> table[i];
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                dfs(i, j, "");
                for(int k = 0; k < MAXN;++k) {
                    memset(vis[k], 0, sizeof(int)*MAXN);
                }
            }
        }
        // sort(words.begin(), words.end(), mySort);
        // for(int i = 0; i < words.size(); ++i) {
        //     cout << words[i] << endl;
        // }  
        for(set<string, custom_compare>::iterator it = words.begin(); it != words.end(); ++it) {
            cout << *it << endl;
        }
        words.clear();

        if(t) cout << endl;
    }
    return 0;
}
