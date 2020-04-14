#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 100009
using namespace std;

int n, k, ith;
int team[MAX];
int skills[MAX];
priority_queue<pair<int, int>> maxSkills;

void putTeam(int id) 
{   
    pair<int, int> choose = maxSkills.top();
    maxSkills.pop();
    int pos = choose.second;
    team[pos] = id;

    int l = 1, d = 1;
    ith = 0;
    while(l <= k && pos-l-ith > 0)
    {
        if(team[pos-l-ith]!=0)
        {
            ++ith;
            continue;
        }
        team[pos-l-ith]=id;
        l++;
    }
    ith = 0;
    while(d <= k && pos+d+ith <= n)
    {
        if(team[pos+d+ith]!=0) {
            ++ith;
            continue;
        }
        team[pos+d+ith]=id;
        d++;
    }
    
    while(!maxSkills.empty() && team[maxSkills.top().second] != 0)
        maxSkills.pop();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
    {
        cin >> skills[i];
        maxSkills.push(make_pair(skills[i], i));
    }

    int i = 0;
    while(!maxSkills.empty())
    {
        putTeam((i++)%2+1);
    }

    for(int i = 1; i <= n; ++i)
        cout << team[i];
    cout << '\n';
    return 0;
}