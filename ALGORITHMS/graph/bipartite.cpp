#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h> // memset
#include <algorithm> // lower_bound

using namespace std;

#define fs first
#define sd second
#define pb push_back
#define vii vector<int>
#define pii pair<int, int>
#define MAXN 120000

const int INF = 0x3f3f3f3f;

int color[MAXN];
vector<int> grafo[MAXN];

// retorna se manteve a consistencia ou não
int bfsColor(int vertice) {
    queue<int> fila;
   
    fila.push(vertice);
    color[vertice] = 1;

    while(!fila.empty()) {
        int atual = fila.front();
        fila.pop();
        for(int i = 0; i < (int)grafo[atual].size(); ++i) {
            int vizinho = grafo[atual][i];
            
            if(color[vizinho] == color[atual])
                return -1; // no bipartite
            
            fila.push(vizinho);
            color[vizinho] = !color[atual];

        }
    }

    return 0; //succes, bipartite
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    memset(color, -1, sizeof color);

    int flag = 0;
    for(int i = 0; i < n; ++i) {
        if(color[i] == -1)
            flag = bfsColor(i);

        if(flag == -1)
            break;
    }

    if(flag == -1)
        cout << "Grafo Não Bipartido\n";
    else 
        cout << "Grafo Bipartido\n";
    return 0;
}