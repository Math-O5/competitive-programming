#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
#define MAX 1001
using namespace std;

int n, m, ans;
string mapa[MAX];
char mar = '.', costa='#';

int check(int i, int j)
{
    if( (i - 1 < 0) || (i+1 == n) || (j+1 == m) || (j-1 < 0)
        || (mapa[i-1][j]==mar)
        || (mapa[i][j-1]==mar)
        || (mapa[i+1][j]==mar)
        || (mapa[i][j+1]==mar) ) 
    {
        return 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0 ; i < n; ++i)
    {
        cin >> mapa[i];     
    }
    
    for(int i = 0 ; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(mapa[i][j]==costa && check(i, j))
                ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
