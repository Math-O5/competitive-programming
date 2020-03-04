#include <iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#define MAX 100009
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    if(a.first < b. first)
        return true;
    else if(a.first == b.first)
        return (a.second > b.second)? true : false;
    return false;
}

vector<int> pontes[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, t, a, b;
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        cin >> t >> a >> b;
        switch(t)
        {
            case 1:
                pontes[a].push_back(b);
                pontes[b].push_back(a);
            break;
            case 0:
                int j = 0;
                for(; j < pontes[a].size(); ++j)
                    if(pontes[a][j]==b)
                    {
                        cout << "1\n";
                        break;
                    }
                if(j == pontes[a].size())
                    cout << "0\n";
            break;
        }
    }
    return 0;
}
