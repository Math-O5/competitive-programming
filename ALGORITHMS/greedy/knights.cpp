/*
    Visite todas posições do tabuleiro com o cavalo
*/
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h> // memset
#include <algorithm> // lower_bound
#include <iomanip>
#include <bitset>
    // #include <bits/stdc++.h>

using namespace std;

#define fs first
#define sd second
#define pb push_back
#define vii vector<int>
#define pii pair<int, int>
#define MAXN 1200

const int INF = 0x3f3f3f3f;

int n;
int marked[MAXN][MAXN], moves[8][2] = { 1, 2,
                                        2, 1
                                        -1, 2,
                                        2, -1,
                                        1, -2,
                                        -2, 1
                                        -1, -2,
                                        -2, -1,
                                        };

bool valid(int pos) {
    return (pos >= 0 && pos < n);
}

void backtracking(int i, int j, int nv) {
    if(k == n * n -1) {
        
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    return 0;
}