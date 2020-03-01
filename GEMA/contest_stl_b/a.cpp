#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char aux;
    set<char> letter;
    while(cin>>aux)
    {
        if(aux>='a' && aux <= 'z')
            letter.insert(aux);
    }
    cout << letter.size() << '\n';
    return 0;
}