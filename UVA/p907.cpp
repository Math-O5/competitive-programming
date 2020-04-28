#include<vector>
#include<iostream>
#include<algorithm>
#include<utility>

using namespace std;

int aux, max_path, night, camps, novo, a ,b ;

vector<int> path;

int main() {
    int x;
    int ans;
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
            int k = night;
            x = (a+b)/2;
            int passing = x;
            novo = 0;
            while(k > 0 && novo < max_path) {
                int i = 0;
                while(passing >= path[i] && i <= camps) {
                    ++i;
                }

                if(path[i] > passing) {
                    novo = path[i-1];
                } else {
                    novo = path[i];
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