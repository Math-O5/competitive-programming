#include <iostream>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

vector<int> v;
int dp[220][40];

int opt(int w, int j) {
    if(j == (int)v.size())
        return 0;

    if(dp[w][j] != -1)
        return dp[w][j];

    if(w < v[j])
        return dp[w][j] = opt(w, j + 1);
    return dp[w][j] = max(v[j] + opt(w - v[j], j + 1), opt(w, j + 1));
}

int main() {
    int m, total, aux;  
    char c;

    cin >> m;
    getchar();

    while(m--) {
        total = 0;
        memset(dp, -1, sizeof dp);

        while(cin >> aux) {
            v.push_back(aux);
            total += aux;

            scanf("%c", &c);
            if(c == '\n') break;
        }

        if(total % 2 != 0)
            cout << "NO\n";
        else if(opt(total/2, 0) == total/2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";          
        }

        v.clear();
    }
}