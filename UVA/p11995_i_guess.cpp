#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int ans[3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b;
    while(cin >> n)
    {
        queue<int> q;
        priority_queue<int> pq;
        stack<int> s;
        ans[0] = ans[1] = ans[2] = 0;
        for(int i = 0; i < n; ++i)
        {
            cin >> a >> b;
            if(a==1)
            {
                q.push(b);
                pq.push(b);
                s.push(b);
            } else {
                if(!q.empty() && b == q.front()) 
                    q.pop();
                else
                    ans[0] = 1;
                if(!pq.empty() && b == pq.top())
                    pq.pop();
                else 
                    ans[1] = 1;
                if(!s.empty() && b == s.top())
                    s.pop();
                else
                    ans[2] = 1;
            }
        }
        if(ans[0] == 1 && ans[1] == 1 && ans[2] == 1)
            cout << "impossible\n";
        else if((ans[0] == 0 && ans[1] == 0 ) || (ans[0] == 0 && ans[2] == 0) || (ans[1] == 0 && ans[2] == 0))
            cout << "not sure\n";
        else if(!ans[0])
            cout << "queue\n";
        else if(!ans[1])
            cout << "priority queue\n";
        else
            cout << "stack\n";
    
    }

    return 0;
}