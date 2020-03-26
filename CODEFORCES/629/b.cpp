#include<iostream>
#include<string>
#define MAX 100010

using namespace std;

const int INF = 0x3f3f3f3f;

long long int a, b, n;

void backtrcking()
{
    int sum = 0, ant = 0, pos1, pos2;
    int i = 1;
    while(sum < b)
    {
        ant = sum;
        sum = sum + i;
        ++i;
    }

    pos1 = a - (i - 1);
    pos2 = a - (b - ant - 1);

    for(int i = 1; i <= a; ++i)
    {
        if(i == pos1 || i == pos2)
            cout << 'b';
        else cout << 'a';
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(long long int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        backtrcking();
    }

    return 0;
}