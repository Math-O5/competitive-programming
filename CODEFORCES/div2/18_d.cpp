#include <iostream>
#include<string>
#include<vector>
#include<string.h>

using namespace std;

long long int win[2050];

long long int power2(int i) {
    if(i == 0)
        return 0;

    int ans = 1;

    for(int j = 0; j < i; ++j) 
        ans *= 2;
    return ans;
}

int main() {
    long long int n, x, flag = 0, tol = 0, resp = 0;
    char s[100];

    cin >> n;
    while(n--) {
        scanf("%s %d", s, &x);
        if(s[0] == 'w') {
            if(flag) {
                memset(win, 0, sizeof win);
                resp += power2(tol);
                tol = 0;
                flag = 0;
            }

            win[x] = x;
        } else {
            flag = 1;
            tol = max(tol, win[x]);
            
        }
    }

    resp += power2(tol);
    cout << resp  << '\n';

    return 0;
}