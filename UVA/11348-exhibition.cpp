#include<bits/stdc++.h>

using namespace std;

int k, n, m, aux;
int friends[51];

int main() {
    cin >> k;
    map<int, int>::iterator it;
    int c = 0;
    while(c++ < k) {
        cin >> n;
        map<int, int> stamps, lockStamp;
        for(int i = 1; i <= n; ++i) {
            cin >> m;
            for(int j = 0; j < m; ++j) {
                cin >> aux;

                // already exist
                if(lockStamp[aux] != 0) {
                    continue;
                }

                it = stamps.find(aux);

                if(it == stamps.end()) {
                    // reserve costs for friend i
                    stamps[aux] = i;
                } else {
                    if(it->second != i) {
                        stamps.erase(it);
                        lockStamp[aux] = 1;
                    }
                }
                
            }
        }

        memset(friends, 0, sizeof(int)*51);
        int total = 0;
        for(it = stamps.begin(); it != stamps.end(); ++it) {
            if(it->second != 0) {
                total += 1;
                friends[it->second]++; 
            }
        }
        cout << "Case " << c << ":";
        for(int i = 1; i <= n; ++i) {
            cout << ' ' << setprecision(6) << fixed <<  100*friends[i]/(double)total << "%";
        }
        cout << endl;
    }
}