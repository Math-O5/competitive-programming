#include <iostream>
#include <string>

using namespace std;

int v[10000];
int maior = -1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> s;
        v[s.size()]++;
        if(v[s.size()] > v[maior])
            maior = s.size();
    }
    cout << maior << '\n';

    return 0;
}
