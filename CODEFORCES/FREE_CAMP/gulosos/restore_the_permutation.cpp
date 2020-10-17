#include<bits/stdc++.h>

using namespace std;

set<int> s;
vector<int> ans;

int main() {
    int t, aux;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1; i <= 2*n; ++i) {
            cin >> aux;
            if(s.find(aux) == s.end()) {
                s.insert(aux);
                cout << aux << ' ';
            }             
        }
        cout << endl;
        s.clear();
    }

    return 0;
}