#include<bits/stdc++.h>
using namespace std;

int match(deque<char> a, deque<char> b)
{
    if(a.empty() || b.empty()) return 0;

    //cout << "___________" << endl;
    while(!a.empty() && !b.empty())
    {
        //cout << "comp " << a.front() << ' ' <<  b.back() << endl;
        if(a.front() != b.back())
        {
            a.pop_front();
            b.pop_back();
        } else {
            return 0;
        }
    }
    if(a.empty() && b.empty())
        return 1;
    return 0;
}

int canConsume(deque<char> a, deque<char> b)
{
    if(a.empty() || b.empty()) return 0;
    deque<char> c;

    while(!a.empty())
    {   
        if(!c.empty() && c.front()==')')
            return 0;
        if(!c.empty() && c.back()=='(' && a.front()==')')
        {
             a.pop_front();
             c.pop_back();
             continue;
        }
        c.push_back(a.front());
        a.pop_front();
    }

    while(!b.empty())
    {   
        if(!c.empty() &&  c.front()==')')
            return 0;
        if(!c.empty() &&  c.back()=='(' && b.front()==')')
        {
             b.pop_front();
             c.pop_back();
             continue;
        }
        c.push_back(b.front());
        b.pop_front();
    }
    return (c.empty())? 1 : 0;
}

int ans = 0;
int use[550000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<deque<char>> a;
    int n, vazio;
    char aux;
    string s;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
       cin >> s;
        deque<char> b;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i]=='(')
                b.push_back('(');
            else if(!b.empty() && b.back()=='(') 
                b.pop_back();
            else
                b.push_back(')');
            
        }
        if(b.empty()) {
           ++vazio; 
           if(vazio%2==0)
            ans++;
        }
        a.push_back(b);
    }

    for(int i = 0; i < a.size(); ++i) {
        int j = i + 1;
        while(j < a.size()) {
            if(use[i]==0 && use[j]==0 && canConsume(a[i], a[j]))
            {
                ++ans;
                use[j]=1;
                ++j;
                break;
            }
            if(use[i]==0 && use[j]==0 && canConsume(a[j], a[i]))
            {
                ++ans;
                use[j]=1;
                ++j;
                break;
            }
            ++j;
        }
    }
    cout << ans << '\n';
    return 0;
}