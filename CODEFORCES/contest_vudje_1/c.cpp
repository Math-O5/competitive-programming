#include<iostream>
#include<vector>
#include<queue>
#define MAX 1000
using namespace std;

long long int t, v[MAX], d, n, ok;
priority_queue<pair<long long int, vector<long long int>>> pq;

void backtrcking(vector<long long int> ans, long long int sum, long long int i)
{
    if(sum > d) {
        return;
    }

    if(sum == d) {
        ok = 1;
    }
    if(i >= n || sum >= d) {
        pq.push(make_pair(sum, ans));
        return;
    }

    ans.push_back(v[i]);
    if(!ok) backtrcking(ans, sum+v[i], i+1);
    ans.pop_back();
    if(!ok) backtrcking(ans, sum, i+1);
}

int main()
{
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cin >> t;
    vector<long long int> ans;

    while(cin >> d)
    {
        cin >> n;
        for(long long int j = 0; j < n; ++j)
            cin >> v[j];
        backtrcking(ans, 0, 0);
        ans = pq.top().second;
        long long int u  = ans.size();
        for(long long int j = 0; j < u; ++j)
            cout << ans[j] << ' ';
        cout << "sum:" << pq.top().first << '\n';
        while(!pq.empty())
            pq.pop();
        ans.clear();
        ok = 0;
    }

    return 0;
}