#include<iostream>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int year, loop, k, qnum[3010];

int main()
{
    string s;
    while(cin >> s, s[0] != '#')
    {
        cin >> year >> loop;
        pq.push(make_pair(loop, year));
        qnum[year] = loop;
    }
    cin >> k;

    while(k--)
    {
        pair<int, int> m = pq.top();
        pq.pop();
        cout << m.second << '\n';
        m.first += qnum[m.second];
        pq.push(m);
        
    }

    return 0;
}