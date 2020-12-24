#include<iostream>

using namespace std;

long long int mmc;

long long int gcd(long long int a, long long int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// (0, ..., b-1), (mmc, mmc + 1, ..., mmc + b - 1), ..., ()
long long int count(long long int r, long long int b) {
    long long int freq = r/mmc;
    long long int tmp = r;
    if(freq != 0) {
        r -= ((freq-1)* b);
        r -= min(b, tmp - (freq*mmc) + 1);
    }

    return r - min(tmp, b-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long int t, r, l, a, b, q;
    cin >> t;
    while(t--) {
        cin >> a >> b >> q;
        if(a > b) {
            int c= a;
            a = b;
            b= c;
        }
        long long int g = gcd(a, b);
        mmc = (a*b)/g;
        

        while(q--) {
            cin >> l >> r;
            
            if(mmc == b || r < b) {
                cout << "0 ";
                continue;
            }

            long long int up = count(r, b);
            if(l-1 > 0)
                up -= count(l-1, b);
            cout << up << ' ';
        }
        cout << '\n';
    }
    return 0;
}