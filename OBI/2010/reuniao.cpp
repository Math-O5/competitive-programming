// source:
// https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h> // memset
#include <algorithm> // lower_bound
#include <iomanip>

using namespace std;

#define fs first
#define sd second
#define pb push_back
#define vii vector<int>
#define pii pair<int, int>
#define MAXN 1200

const int INF = 0x3f3f3f3f;

// Matriz de adjacencia
int grafo[MAXN][MAXN];

/**
 *  A^(k) = min { A^(k-1)[i][j], A^(k-1)[i][k] + A^(k-1)[k][j] }
 */
void floydWarshall(int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                grafo[i][j] = min(grafo[i][j], grafo[i][k] + grafo[k][j]); 
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            grafo[i][j] = INF;
            if(i == j)
                grafo[i][j] = 0;
        }
    }

    int a, b, c;
    for(int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        grafo[a][b] = c;
        grafo[b][a] = c;
    }

    floydWarshall(n);

    int ans = INF, minLinha;
    for (int i = 0; i < n; ++i) {
        minLinha = 0;
        for (int j = 0; j < n; ++j) {
            if(grafo[i][j] != INF) {
                minLinha = max(minLinha, grafo[i][j]);
            }
        }

        ans = min (ans, minLinha);
    }

    cout << ans << endl;
    return 0;
}