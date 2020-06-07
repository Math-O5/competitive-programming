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

// Breath First Search
void bfs(int v) 
{
    queue<int> q;

    // q : v
    q.push(v);
    component[v] = v; 
    
    // while is not empty
    while(!q.empty())
    {
        int no = q.front();
        q.pop();

        // for every neighboor of no
        for(int i = 0; i < grafo[no].size(); ++i)
        {
            // if the it has been no visited insert neighboors of node v in queue q
            if(component[grafo[no][i]] == UNVISITED)
            {
                component[grafo[no][i]] = component[no];
                q.push(grafo[no][i]);
            }
        }
    }
}


int main() 
{
    // start vertice (node)
    int v = 0;
    
    // mark all nodes with unvisited
    memset(component, UNVISITED, sizeof component);
    
    bfs(v);

    return 0;
}