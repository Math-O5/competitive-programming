#include<bits/stdc++.h>

using namespace std;

int t, n, m, field[31][31];

int myPath() {
    // int cardinalidade = n + m - 1;
    int secondsDiags[n + m][2] = {0};
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            secondsDiags[i + j][field[i][j]]++; 
            // cin >> field[i][j];
        }
    }

    for(int i = 0; i < n + m - 1; ++i) {
        int j = n + m - 2 - i;
        if(i <= j) continue;
        ans += min(secondsDiags[i][0] + secondsDiags[j][0], secondsDiags[i][1] + secondsDiags[j][1]);
    }

    return ans;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> field[i][j];
            }
        }
        cout << myPath() << endl;
    }
    return 0;
}