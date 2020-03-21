#include<iostream>

using namespace std;

int n, x, ans;

int power(int a)
{
    int ansR = 1, b = n;
    while(b--)
    {
        ansR *= a;
    }
    return ansR;
}

void backtracking(int sum, int num)
{
    if(sum == x)
    {
        ++ans;
        return;
    }
    if(sum > x || power(num) > x)
        return;

    backtracking(sum+power(num), num+1);
    backtracking(sum, num+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> x >> n;
    backtracking(0,1);
    cout << ans << '\n';
    return 0;
}