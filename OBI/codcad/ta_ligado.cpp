#include <bits/stdc++.h>

using namespace std;

vector<int> grafo[100008];
int M, N, T, A, B, ans;
int main()
{
    cin >> N >> M;
    for(int i = 0; i < M; ++i)
    {
        cin >> T >> A >> B;
        if(T){ grafo[A].push_back(B); grafo[B].push_back(A); }
        else {
            for(int i = 0; i < grafo[A].size(); ++i){
                if(grafo[A][i] == B){ ans = 1; break; }
            }
            cout << ans << endl;
            ans = 0;
        }

    }
    return 0;
}