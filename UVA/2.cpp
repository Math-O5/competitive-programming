#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;

int n, m;

void backtrack(string ans, string s, vector<string> d, int k) {
    if(k ==  int(s.size())) {
        cout << ans << endl;
        return;
    }
    
    if(s[k] == '#') {
        for(int i = 0; i < int(d.size()); ++i)
        {
            string aux = ans + d[i];
            backtrack(aux, s, d, k+1);
        }

    } 
    else 
    {
        for(int i = 0; i <= 9; ++i)
        {
            string aux = ans + char('0'+i);
            backtrack(aux, s, d, k+1);
        }
    }
}

int main()
{
    string s;
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    
    while(cin >> n)
    {
        string s1;
        vector<string> d;
        cout << "--\n";
        for(int i = 0; i < n; ++i)
        {
            cin >> s;
            d.push_back(s);
        }
        cin >> m;
        for(int i = 0; i < m; ++i)
        {
            cin >> s;
            backtrack(s1, s, d, 0);
        }
    }
    return 0;
}