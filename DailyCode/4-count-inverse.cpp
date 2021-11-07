#include <bits/stdc++.h>

using namespace std;

#define fs first
#define sd second
#define pb push_back
#define vii vector<int>
#define pii pair<int, int>
#define MAXN 200005


void update(int bts[], int value, int maxn) {
    while(value <= maxn) {
        // count frequence
        bts[value] += 1;
        value += value&(-value);
    }
}

// The maxium value is 10^5, 
long long int sum(int bts[], int value) {
    long long int sum = 0;
    while(value > 0) {
        // count frequence
        sum += bts[value];
        value -= value&(-value);
    }
    return sum;
}

int compressArray(vector<int>& A, vector<int>& B, int N) {
    sort(B.begin(), B.begin()+N);
    map<int, queue<int>> mp;
    int cnt = 1;
    for(int i = 0; i < N; ++i) {
        mp[B[i]].push(cnt);
        ++cnt;
    }
    
    for(int i = 0; i < N; ++i) {
        int tmp =  A[i];
        A[i] = mp[A[i]].front();
        mp[tmp].pop();
    
    }
    return cnt;

}

int main() {
    vector<int> A(MAXN), B(MAXN);
    int bts[MAXN+1];
    int N, T;
    int maxn;

    long long int ans;
    string line;
    cin >> T;

    while(T > 0) {
        cin >> N;
        ans = 0;
        for(int i = 0; i < N; ++i) {
            cin >> A[i];
            B[i] = A[i];
        }
        
        maxn = compressArray(A, B, N)-1;
        memset(bts, 0, sizeof(int)*(maxn+1));

        for(int i = N-1; i >=0; --i) {
            ans += sum(bts, A[i]);
            update(bts, A[i], maxn);
        }

        cout << ans << "\n";

        if(T > 1)
            getline(cin, line);
            
        T -= 1;
    }

    return 0;
}