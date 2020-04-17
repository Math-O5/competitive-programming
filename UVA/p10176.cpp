#include<iostream>

using namespace std;

const int p = 131071;
int sum, i, power;
char c;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> c) {
        if(c == '#') {
            if(sum % p == 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }

            i = 0;
            sum = 0;
            power = 1;
        }
        
        if(c == '0' || c == '1') {
            sum = ( sum + ((int)(c-'0')*power) ) % p;
            ++i;
            power *= 2;
        }
    }

    return 0;
}