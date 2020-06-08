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


struct edge {
    int from, to, value;
};

int n, m, start;
vector<edge> Edge;


/**  
 *  source: https://cp-algorithms.com/graph/bellman_ford.html
 * 
 */
void bellmanFord() {
    vector<int> distance (n, INF);

    distance[start] = 0;

    // relaxion process
    for(int i = 0; i < n - 1; ++i) {
        
        // for all edges
        for(int j = 0; j < m;++j) {

            // if this vertice is reachble 
            if(distance[ Edge[j].from ] < INF) {              
                distance[ Edge[j].to ] = min( distance[ Edge[j].to ], distance[ Edge[j].from] + Edge[j].value );
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    return 0;
}