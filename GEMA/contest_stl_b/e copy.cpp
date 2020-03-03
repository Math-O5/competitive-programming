#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 100009
using namespace std;
 
int n, k, ith;
int team[MAX];
int skills[MAX];
vector<int> v;
priority_queue<pair<int, int>> maxSkills;
 
void putTeam(int id) 
{   
    pair<int, int> choose = maxSkills.top();
    maxSkills.pop();
    int pos = choose.second;
    team[pos] = id;
 
    int l = 1, d = 0;

    while(d <= k && )
    {
        if(team[pos+d+ith]!=0) {
            ++ith;
            continue;
        }
        team[pos+d+ith]=id;
        d++;
    }

    while(l <= k && pos-l > 0)
    {
        if(team[pos-l-ith]!=0)
        {
            ++ith;
            continue;
        }
        team[pos-l-ith]=id;
        l++;
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
        v.push_back(skills[i]);
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