#include<iostream>
#include<vector>
#include<string>

using namespace std;

int c, m, l, num;
string str;

int main() {
    cin >> c;
    while(c--) {
        int left = 0, right = 0;
        int ansL = 0, ansR = 0;

        cin >> l >> m;
        l *= 100; 
        for(int i = 0; i < m; ++i) {
            cin >> num >> str;
            if(str[0] == 'l') {
                if(num + left <= l) {
                    left += num;
                } else {
                    // cross river
                    left = num;
                    ansL++;
                }
            } else {
                if(num + right <= l) {
                    right += num;
                } else {
                    right = num;
                    ansR++;
                }
            }
        }

        if(left) ansL++;
        if(right) ansR++;
        
        if(ansL > ansR) {
            if(ansL == 1) 
                cout << 1 << endl;
            else cout << 2* ansL - 1 << endl;
        } else cout << 2* ansR << endl;
    }
}