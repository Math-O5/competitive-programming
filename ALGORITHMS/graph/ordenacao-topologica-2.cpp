#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

#define MAX 100000
#define UNVISITED -1

using namespace std;

int component[MAX],
    grau[MAX];
vector<int> grafo[MAX],
            orderedTop;

/**
 * 
 * Graph is unweighted, 
 * or all distances are one between two vertices adjacent.
 * 
 */
// Deep First Search
void dfs(int v)
{

    component[v] = 1;
    
    // For every neighboor of v
    for(int i = 0; i < grafo[v].size(); ++i)
    {
        if(component[grafo[v][i]] == UNVISITED)
        {
            // mark as visited
            
            // explore neighboors
            dfs(grafo[v][i]);
        }
    }
    orderedTop.push_back(v);
}


int main() {
    int n, m, v, a, b;
    
    // the vertice is marked as 1 to n
    cin >> n >> m;

    // Building list adjacent
    for(int i = 0; i < m; ++i) {
        cin >> a >> b;

        grafo[a].push_back(b);
        grau[b] += 1;
    }

    memset(component, UNVISITED, sizeof component);

    for(int i = 1; i <= n; ++i) {
        if(component[i] == UNVISITED) 
            dfs(i);
    }
    
    if(orderedTop.size() < n) {
        cout << "Impossivel\n";
        return 0;
    }
    for(int i = n - 1; i >= 0; --i) {
        cout << orderedTop[i] << endl;
    }
    return 0;
}