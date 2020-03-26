#include<iostream>
#include<string>
#define MAX 200010

using namespace std;

const int INF = 0x3f3f3f3f;

int n;
string a, b;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, i;
    string s;
    cin >> t;
    for(int j = 0; j < t; ++j)
    {
        cin >> n;
        cin >> s;
        a.clear(); b.clear(); i = 0;
        while(i <= n-1)
        {
            if(a == b)
            {
                if(s[i]=='2')
                {
                    a.push_back('1');
                    b.push_back('1');
                } else if(s[i]=='1') {
                    a.push_back('1');
                    b.push_back('0');
                } else {
                    a.push_back('0');
                    b.push_back('0');
                }
            }
            else if(b > a)
            {
                if(s[i]=='2')
                {
                    a.push_back('2');
                    b.push_back('0');
                } else if(s[i]=='1') {
                    a.push_back('1');
                    b.push_back('0');
                } else {
                    a.push_back('0');
                    b.push_back('0');
                }
            } else {
                if(s[i]=='2')
                {
                    b.push_back('2');
                    a.push_back('0');
                } else if(s[i]=='1') {
                    b.push_back('1');
                    a.push_back('0');
                } else {
                    a.push_back('0');
                    b.push_back('0');
                }
            }
            ++i;
        }
        a.push_back('\n');
        b.push_back('\n');
        cout << a;
        cout << b;
    }
    return 0;
}