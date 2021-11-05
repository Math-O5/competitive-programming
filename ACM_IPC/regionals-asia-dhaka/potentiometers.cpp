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
    #define MAXN 200005

    const int INF = 0x3f3f3f3f;

    int A[MAXN], bit[MAXN+1], N;
    string op;

    void update(int x, int value) {
        while(x <= N + 1) {
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
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int numCase = 1;

        while(cin >> N, N > 0) {
            if(numCase > 1)
                cout << '\n';

            cout << "Case " << numCase << ":\n";
            for(int i = 1; i <= N; ++i) {
                cin >> A[i];
                update(i, A[i]);
            }
            

            while(cin >> op, op != "END") {
                if(op == "M") {
                    int l, r;
                    cin >> l >> r;
                    cout << query(l, r) << "\n";
                } else {
                    int i, v;
                    cin >> i >> v;
                    update(i, v-A[i]);
                    A[i] = v;
                }
            }
            numCase += 1;
            memset(bit, 0, sizeof(int)*(N+1));
        }


        return 0;
    }