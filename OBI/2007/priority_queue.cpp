#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;

int ans[10000];

int main()
{
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int n, l, aux;
    cin >> n >> l;
    for(int i = 1; i <= l; ++i)
    {
        cin >> aux;
        if(i <= n)
        {
            pq.push(make_pair(aux, i));
            ans[i]++;
            continue;
        }

        pair<int, int> m = pq.top();
        pq.pop();
        m.first += aux;
        ans[m.second]++;
        pq.push(m);
    }
    
    for(int i = 1; i <= n; ++i) 
        cout << i << ' ' << ans[i] << '\n';

    return 0;
}