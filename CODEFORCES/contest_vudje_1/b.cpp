 
#include<iostream>

using namespace std;

int k;

bool isK(int x) {
    int sum = 0;
    while(x > 0)
    {
        sum += x%10;
        x /= 10;
    }
    return (sum==10);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    int ans = 19;
    for(int i = 1; i < k;)
    {
        ans += 9;
        if(isK(ans))
            ++i;
    }
    cout << ans << '\n';
    return 0;
}