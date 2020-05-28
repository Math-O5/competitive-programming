// problem:
// https://s3-us-west-2.amazonaws.com/prod-runcodes-files/exercisefiles/14617/2520%20--%20DNA%20Sequence%20Alignment.pdf?X-Amz-Content-Sha256=e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855&X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAI3OUHGVPPSQMGO5Q%2F20200528%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20200528T222135Z&X-Amz-SignedHeaders=Host&X-Amz-Expires=120&X-Amz-Signature=f3640ff3afe9a0184271e986b2a87af367221b1bb74659be9559cbb7450d74fa
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h> // memset
#include <algorithm> // lower_bound

using namespace std;

#define fs first
#define sd second
#define pb push_back
#define MAXN 1500
#define DASH 4

const int INF = 0x3f3f3f3f;

string seqA, 
       seqB;
int dp[MAXN][MAXN],
    cost[5][5] = {
                    {0, 5, 5, 5, 3},
                    {5, 0, 4, 5, 3},
                    {5, 4, 0, 5, 3},
                    {5, 5, 5, 0, 3},
                    {3, 3, 3, 3, INF},
                };

int Min(int a, int b, int c) {
    return min(a, min(b, c));
}

int convertChar(char c) {
    switch (c) {
    case 'A':
        return 0;
    case 'G':
        return 1;
    case 'C':
        return 2;
    case 'T':
        return 3;
    default:
        return 4;
    }
}

int distancia(int n, int m) {
    if(n < 0 || m < 0) {
        if(n < 0 && m < 0) 
            return 0; 
        if(n >= 0) {
            return distancia(n-1, m) + cost[convertChar(seqA[n])][DASH];
        }

        if(m >= 0) {
            return distancia(n, m-1) + cost[convertChar(seqB[m])][DASH];
        }
    }


    if(dp[n][m] != -1)
        return dp[n][m];
        
    /*
        There is only three possibilite to alignment, dash letter, letter dash or letter letter
    */ 
   int a = convertChar(seqA[n]),
       b = convertChar(seqB[m]); 
   return dp[n][m] = Min( distancia(n-1, m) + cost[a][DASH], 
                distancia(n, m-1) + cost[b][DASH],
                distancia(n-1, m-1) + cost[a][b]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    while(cin >> seqA >> seqB) {
        n = (int)seqA.size();
        m = (int)seqB.size();
        memset(dp, -1, sizeof dp);
        cout << distancia(n-1, m-1) << endl;
    }
    return 0;
}