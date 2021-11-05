#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h> // memset
#include <algorithm> // lower_bound
#include <iomanip>
#include <bitset>
#include <unordered_map>
    // #include <bits/stdc++.h>

using namespace std;

#define fs first
#define sd second
#define pb push_back
#define vii vector<int>
#define pii pair<int, int>
#define MAXN 120000

const int INF = 0x3f3f3f3f;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, y;
    cin >> y >> n;

    int pos[y+1];
    int a, b, j, placed, unlucky;

    for(int i = 1; i <= y; ++i) {
        cin >> pos[i];
    }

    for(int i = 0; i < n; ++i) {
        cin >> a >> placed >> b;

        j = 0;
        unlucky = 0;
        
        if(pos[a] >= placed)
            j = b + 1;
            
        while(j < b) {
            j += 1;
            if(pos[a + j] >= placed) {
                unlucky += 1;
            }
        }

        cout << unlucky << "\n";
    }
    
    return 0;
}