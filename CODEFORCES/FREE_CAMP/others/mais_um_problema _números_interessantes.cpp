#include<iostream>

using namespace std;

long long int a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    cout << (b + b - a + 1)*a/2 << '\n';
    return 0;
}