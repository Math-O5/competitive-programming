#include<bits/stdc++.h>

using namespace std;

#define MAXN 100000

int num[MAXN], lis[MAXN], n, aux, t;

int main() {

    while(1) {
        cin >> aux;
        if(aux==-1) {
            break;
        } else if(t > 0) cout << endl;
        ++t;

        n = 0;
        num[n++] = aux; 

        while(cin >> aux, aux!=-1) {
            num[n++] = aux;
        }
        lis[0] = 1;
        int ans = 0;
        for(int i = 1; i < n; ++i) {
            lis[i] = 1;
            for(int j = 0; j < i; ++j) {
                if(num[j] >= num[i]) {
                    lis[i] = max(lis[i], lis[j] + 1);
                    ans = max(lis[i], ans);
                }
            }
        }

        if(n==1)
            ans = 1;
        cout << "Test #" << t <<":\n  maximum possible interceptions: " << ans << endl;
    }
    return 0;
}