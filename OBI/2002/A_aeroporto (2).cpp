#include <iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#define MAX 100009
using namespace std;

int a, v, j, x, y;
vector<pair<int, int>> voo;

bool comp(pair<int, int> a, pair<int, int> b)
{
    if(a.first < b. first)
        return true;
    else if(a.first == b.first)
        return (a.second > b.second)? true : false;
    return false;
}

int main()
{
    j = 1;
    while(cin >> a >> v, a > 0 && v > 0)
    {
        
        cout << "Teste " << j << '\n';
        
        for(int i = 0; i <= a; ++i)
        {
            voo.push_back(make_pair(0, i));    
        }
        
        for(int i = 0; i < v; ++i)
        {
            cin >> x >> y;
            
            voo[x].first++;
            voo[y].first++;
        }
        sort(voo.begin(), voo.end(), comp);
        int strongest = voo[a].first, l = a;
        
        while(voo[l].first == strongest)
        {
            cout << voo[l].second << ' '; 
            l--;
        }
        
        cout << "\n\n";
        ++j;
        voo.clear();
    }


    return 0;
}
