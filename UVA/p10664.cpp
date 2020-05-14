#include <iostream>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

vector<int> v;
int dp[420][220];

int opt(int w, int j) {
    if(j == (int)v.size())
        return 0;

    if(dp[w][j] != -1)
        return dp[w][j];

    if(w < v[j])
        return dp[w][j] = opt(w, j + 1);
    return dp[w][j] = max(v[j] + opt(w - v[j], j + 1), opt(w, j + 1));
}

int main() {

    int m, total, aux;  
    char c;

    scanf("%d", &m);
    getchar();

    while(m--) {
        total = 0;
        memset(dp, -1, sizeof dp);
        while(scanf("%d", &aux) != EOF) {
            v.push_back(aux);
            total += aux;

            scanf("%c", &c);
            if(c == '\n' || c == '\r') {
                if(c == '\r')
                    scanf("%c", &c);
                break;
            }
        }

        if(total % 2 != 0)
            printf("NO\n");
        else if(opt(total/2, 0) == total/2) {
            printf("YES\n");
        } else {
            printf("NO\n");          
        }

        fflush(stdout);
        v.clear();
    }
    fflush(stdout);
}