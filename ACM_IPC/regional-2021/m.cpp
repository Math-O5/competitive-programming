#include <bits/stdc++.h>

using namespace std;

#define MAX 100005
#define UNVISITED -1

using namespace std;

int component[MAX];
vector<int> grafo[MAX];
bool isDead[MAX];
int pai[MAX], filho_candidato[MAX];

int dfs(int monarca) {
    if(isDead[monarca] == false) {
        return monarca;
    }

    int new_m = -1;
    for(int i = 0; i < (int) grafo[monarca].size(); ++i) {
        new_m = dfs(grafo[monarca][i]);
        if(new_m != -1)
            return new_m;
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q, t, x;
    cin >> q;
    int child = 2, monarca = 1;
    pai[1] = 1;
    for(int i = 0; i < q; ++i) {
        cin >> t >> x;
        if(t == 1) {
            grafo[x].push_back(child);
            pai[child] = x;
            child++;
        } else {
            isDead[x] = true;

            while(isDead[monarca]) {
                int &filho = filho_candidato[monarca];
                if(filho == grafo[monarca].size()) {
                    monarca = pai[monarca];
                } else {
                    monarca = grafo[monarca][filho];
                    ++filho;
                }
            }
            cout << monarca << "\n";
        }
    }
    return 0;
}