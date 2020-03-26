#include<iostream>
#define MAX 100010

using namespace std;

const int INF = 0x3f3f3f3f;

long long int a, b, n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(long long int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        long long int ans = 0;
        if(a%b==0)
        {
            cout << "0\n";
            continue;
        }
        ans += a%b;
        cout << b - ans << '\n';
    }

    return 0;
}