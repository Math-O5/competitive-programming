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
#define MAXN 120000

const int INF = 0x3f3f3f3f;

// Rede 192.168.9.1 & mask_ipv4 => 192.168.9.0 
int mask_ipv4[4] = {255, 255, 255, 0};
int mask_floating = 240;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long int n;
    cin >> n;

    // union
    mask_ipv4[3] |= mask_floating;
    
    // intersection
    mask_ipv4[3] &= mask_floating;

    cout << mask_ipv4[3] << endl;
    
    return 0;
}