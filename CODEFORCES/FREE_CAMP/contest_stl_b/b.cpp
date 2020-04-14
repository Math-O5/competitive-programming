
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, int> names;
    int n;
    string s;
    cin >> n;
    while(n--)
    {
        cin >> s;
        if((names[s])==0) {
            cout << "OK\n";
            names[s]++;
        }
        else {
            cout << s << (names[s]++) << '\n';
        }
    }

    return 0;
}