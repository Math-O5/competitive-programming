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

#define MAX 120000
#define UNVISITED -1

const int INF = 0x3f3f3f3f;

int nivel[MAX], pai[MAX];
vector<int> grafo[MAX];

/**
 * 
 * Graph is unweighted, 
 * or all distances are one between two vertices adjacent.
 *
 * This will mark the nivel
 * First father is nivel 0, then 1 and so on
 * 
 *  0
 * 1  1
 * 2 2 2
 * ...
 */

// Breath First Search
void bfs(int v) 
{
    queue<int> q;

    // q : v
    q.push(v);
    nivel[v] = 0; 
    
    // while is not empty
    while(!q.empty())
    {
        int no = q.front();
        q.pop();

        // for every neighboor of no
        for(int i = 0; i < grafo[no].size(); ++i)
        {
            // if the it has been no visited insert neighboors of node v in queue q
            if(nivel[grafo[no][i]] == UNVISITED)
            {
                pai[grafo[no][i]] = no;
                nivel[grafo[no][i]] = nivel[no] + 1;
                q.push(grafo[no][i]);
            }
        }
    }
}

int lca(int a, int b) {
    // Until commum ancestral
    while(a != b) {
        if(nivel[a] > nivel[b]) {
            a = pai[a];
        } else {
            b = pai[b];
        }
    }
    return b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(nivel, UNVISITED, sizeof nivel);
    int n;
    cin >> n;
    return 0;
}