#include <bits/stdc++.h>

using namespace std;

int i, j, n, ans, resp, jin;
string s;

int main()
{
    string t[6] = {"RGB", "RBG", "BRG", "BGR", "GRB", "GBR"};
    cin >> n >> s;
    for(ans = n; i < 6; ++i) {
        for(resp = j = 0; j < n; ++j) resp += (s[j] != t[i][j%3]);
        if(ans > resp) {
            ans = resp;
            jin = i;
        }  
    }
    
    cout << ans << endl;
    for(j = 0; j < n; ++j) cout <<  t[jin][j%3];
    cout << endl;
    return 0;
}