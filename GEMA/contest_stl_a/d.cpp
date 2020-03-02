#include<iostream>
#include<stack>
#define MAX 1000000
using namespace std;
 
char aux;
stack<char> p;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(cin >> aux)
    {
        if(aux=='(')
            p.push(aux);
        else
        {
            if(p.empty() || p.top()==')')
            {
                cout << "NO\n";
                return 0;
            }
            p.pop();
        }
            
    }
    if(p.empty())
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}