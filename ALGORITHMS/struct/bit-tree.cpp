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

int A[MAXN], bit[MAXN], N;

void update(int x, int value) {
    while(x <= N) {
        bit[x] += value;
        x += x&(-x);
    }
}

int query(int x) {
    int sum = 0;
    while(x > 0) {
        sum += bit[x];    
        x -= x&(-x); // x - lsb(x)
    }
    return sum;
}

int query(int l, int r) {
    return query(r) - query(l - 1);
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int op, q;
    cin >> N >> q;

    for(int i = 1; i <= N; ++i) {
        cin >> A[i];
        update(i, A[i]);
    }
    
    while(q--) {
        cin >> op;
        if(op == 1) {
            int l, r;
            cin >> l >> r;
            cout << query(l, r) << endl;
        } else {
            int i, v;
            cin  >> i >> v;
            update(i, -A[i]);
            update(i, v);
        }
    }

    return 0;
}