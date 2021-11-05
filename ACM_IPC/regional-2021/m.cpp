#include <bits/stdc++.h>

using namespace std;

#define fs first
#define sd second
#define pb push_back
#define vii vector<int>
#define pii pair<int, int>
#define MAXN 120000

const int INF = 0x3f3f3f3f;

#define MAX 100005
#define UNVISITED -1

using namespace std;

int component[MAX];
set<int> grafo[MAX];
bool isDead[MAX];
int pai[MAX];
set<int>::iterator itr;

int dfs(int monarca) {
    if(isDead[monarca] == false) {
        return monarca;
    }

    if(grafo[monarca].empty())
        return -1;

    int new_m = -1;
    for(itr = grafo[monarca].begin(); itr != grafo[monarca].end(); ++itr) {
        new_m = dfs(*itr);
        if(new_m != -1)
            return new_m;
    }

    grafo[pai[monarca]].erase(monarca);

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
            grafo[x].insert(child);
            pai[child] = x;
            child++;
        } else {
            isDead[x] = true;

          
            if(pai[x] == x) {
                for(itr = grafo[x].begin(); itr != grafo[x].end(); ++itr) {
                    if(isDead[*itr] == false) {
                        pai[x] = *itr;
                        break;
                    }
                }
            }

            else  if(pai[x] != x and !grafo[x].empty()) {
                for(itr = grafo[x].begin(); itr != grafo[x].end(); ++itr) {
                    pai[*itr] = pai[x]; 
                }
            }

            if(!grafo[x].empty())
                grafo[pai[x]].erase(x);


            while(isDead[monarca]) {
                int res = dfs(monarca);
                if(res == -1)            
                    monarca = pai[monarca];
                else monarca = res;
            }

            
            cout << monarca << "\n";
        }
    }
    return 0;
}