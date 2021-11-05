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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int b, l;
    cin >> b >> l;

    ++b;

    int alg[l + 1], sp = 0, si = 0;
    for(int i = 0; i < l; ++i) {
        cin >> alg[i];
        if(i % 2 == 0) {
            sp += alg[i];
        } else {
            si += alg[i];
        }
    }

    int diff = sp - si;
    
    if(diff == 0 || (double)diff / (double)b == 1.0 || ((double)diff / (double)b) == -1.0) {
        cout << "0 0\n";
        return 0;
    }
    else {

        if(diff > 0) {
            diff = diff - (b *(int)(diff / b));
            for(int i = 0; i < l; i ++) {

                if(sp - si - alg[i] == 0) {
                    cout << i + 1 << " 0\n";
                    return 0;
                }

                if(i % 2 == 0) {
                    if(alg[i] - diff >= 0) {
                        cout << i + 1 << ' ' << (alg[i] - diff) << '\n';
                        return 0;
                    }
                } else {
                    if(alg[i] - (b-diff) >= 0) {
                        cout << i + 1 << ' ' << (alg[i] - (b-diff)) << '\n';
                        return 0;
                    }
                }
            }

        } else {
            diff = diff + (b *(int)(diff / b));
            for(int i = 0; i < l; i ++) {

                if(sp - si - alg[i] == 0) {
                    cout << i + 1 << " 0\n";
                    return 0;
                }

                if(i % 2 == 0) {
                    if((alg[i] - (diff+b)) >= 0) {
                        cout << i + 1 << ' ' << (alg[i] - (diff+b)) << '\n';
                        return 0;
                    }
                } else {
                    if(alg[i]-(-diff) >= 0) {
                        cout << i + 1 << ' ' << alg[i]-(-diff) << '\n';
                        return 0;
                    }
                }
            }
        }

        
    } 

    cout << "-1 -1\n";
    return 0;
}