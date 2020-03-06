#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<string>
#include<stack>
#define MAX 100000
using namespace std;

int elementos[MAX], n, t, ok;
map<string, int> match;
stack<vector<int>> pilha;

void sumAll(int k, int sum, vector<int> v) {
    //cout << k << ' ' << sum << '\n';
    if(k > n || sum > t)
    {
        return;
    } 
    else if(sum == t) 
    {
        pilha.push(v);
        ok = 1;
    } else 
    {
        sumAll(k+1, sum, v);
        v.push_back(elementos[k]);
        sumAll(k+1, sum+elementos[k], v);
    }
}

bool valid(vector<int> v) 
{
    string s;
    for(int i = 0; i < int(v.size()); ++i)
    {
        while(v[i] > 0)
        {
            s.push_back(char('0'+(v[i]%10)));
            v[i] /= 10;
        }
    }
    s.push_back('\n');
    //cout << s << match[s] << endl;
    if((match[s])==0)
    {
        match[s] = 1;
        return true;
    } 
    return false;
}

void imprimir() {

    while(!pilha.empty())
    {
        vector<int> v = pilha.top();
        pilha.pop();
        if(valid(v)==true)
        {
            int i = 0;
                for(; i< int(v.size()-1); ++i)
                    cout << v[i] << '+';
                if(i < int(v.size()))
                    cout << v[i] << '\n';
                else
                    cout << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(cin >> t >> n && n > 0 && t > 0)
    {
        vector<int> v;
        for(int i = 0; i < n; ++i)
        {
            cin >> elementos[i];
        }
        ok = 0;
        cout << "Sums of " << t << ":\n";
        sumAll(0, 0, v);
        if(!ok)
            cout << "NONE\n";
        else
            imprimir();
        match.clear();

    }   
    return 0;
}