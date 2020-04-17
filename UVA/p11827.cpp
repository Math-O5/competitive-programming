#include<iostream>
#include<vector>
using namespace std;

int n, m, big;
char c;

int gcd(int a, int b) { return (b == 0)? a : gcd(b, a % b); }

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        vector<int> vi;
        big = 0;
        
        while(scanf("%d%c", &m, &c) != EOF) {
            vi.push_back(m);
            if(c != ' ') {
                break;
            }
        }

        for(int i = 0; i < (int)vi.size() - 1; ++i) {
            for(int j = i + 1; j < (int)vi.size(); ++j) {
                big = max(big, gcd(vi[i], vi[j]));
            }
        }

        cout << big << '\n';
    }
    return 0;
}