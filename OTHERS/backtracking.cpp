#include<iostream>
#include<string>
#include<set>
using namespace std;

int n, m;
string s;
set<string> dici;

void backtracking(string b, string ans, unsigned int i)
{

    if(i >= s.size() && b == "")
    {
        cout << ans;
        return;
    } else if(i >= s.size())
        return;
    
    b.push_back(s[i]);
    if(dici.find(b)!=dici.end())
    {
        ans.append(b);

        if(i == s.size()-1)
            ans.push_back('\n');
        else
            ans.push_back(' ');

        backtracking("", ans, i+1);
    
        for(unsigned int j = 0; j <= b.size(); ++j)
            ans.pop_back();
    }
    backtracking(b, ans, i+1);
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> s;
        dici.insert(s);
    }
    cin >> m;
    string b = "";
    for(int i = 0; i < m; ++i)
    {
        cin >> s;
        backtracking("","", 0);
        if(i < m-1)
            cout << '\n';
    }
    return 0;
}
