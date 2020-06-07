#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

#define MAX 100000
#define UNVISITED -1

using namespace std;

int component[MAX];
vector<int> grafo[MAX];

/**
 * 
 * Graph is unweighted, 
 * or all distances are one between two vertices adjacent.
 * 
 */

// Deep First Search
void dfs(int v)
{

    // For every neighboor of v
    for(int i = 0; i < grafo[v].size(); ++i)
    {
        if(component[grafo[v][i]] == -1)
        {
            // mark as visited
            component[grafo[v][i]] = component[v];
            
            // explore neighboors
            dfs(grafo[v][i]);
        }
    }
}

int main() {
    int v = 0;
    
    // mark all nodes with unvisited
    memset(component, UNVISITED, sizeof component);
    
    component[v] = v; 
    dfs(v);

    return 0;
}