#include<vector>
#include<iostream>
#include<algorithm>
#include<utility>

using namespace std;

int aux, max_path, night, camps, novo, a ,b, x, ans, passing, k;

vector<int> path;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> camps >> night) {
        max_path = 0;
        path.push_back(0);
        for(int i = 0; i <= camps; ++i) {
            cin >> aux;
            max_path += aux;
            path.push_back(max_path);
        }
        a = 0, b = max_path; 
        ans = max_path;
        while(a <= b) {
            k = night;
            x = (a+b)/2;
            passing = x;
            novo = 0;
            while(k > 0 && novo < max_path) {
                vector<int>::iterator it = lower_bound(path.begin(), path.end(), passing);
                if(*it > passing || *it == 0) {
                    novo = *(--it);
                } else {
                    novo = *it;
                }

                passing = novo + x;
                 --k;
            }
            if(novo + x >= max_path) {
                ans = min(ans, x);
                b = x - 1;
            } else if(k == 0) {
                a = x + 1;
            }
        }

        cout << ans << '\n';
        path.clear();
    }
    return 0;
}