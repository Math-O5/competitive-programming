#include <iostream>

using namespace std;

int dp[20][20][20];

int solve(int a, int b, int c) {
    if(a < 0 || b < 0 || c < 0) {
        return 0;    
    }
    
    if(a == 0 || b == 0 || c == 0) 
        return 1;
    
    if(dp[a][b][c]) {
        return dp[a][b][c];    
    } else 
        return dp[a][b][c] = solve(a - b, b, c) + solve(a, b, c - b) +
                             solve(a - c, b, c) + solve(a, b - c, c) + 
                             solve(a, b - a, c) + solve(a, b, c - a);
}

int main()
{
    int a, b, c;
    
    cin >> a >> b >> c;
    
    cout << solve(a, b, c) << endl;
    
    return 0;
}
