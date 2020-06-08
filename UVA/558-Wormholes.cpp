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
#define MAXN 1020

const int INF = 0x3f3f3f3f;

struct edge {
    int from, to, value;
};

int n, m, c;
edge e;
vector<edge> Edge;


void bellmanFord() {
    int flag = 0;
    vector<int> distance (n + 1, INF);

    distance[0] = 0;

    // relaxion process
    for(int i = 0; i < n; ++i) {
        flag = 0;
        // for all edges
        for(int j = 0; j < m;++j) {

            // if this vertice is reachble 
            if(distance[ Edge[j].from ] < INF) {
                
                if(distance[ Edge[j].to ] > distance[ Edge[j].from] + Edge[j].value) {
                    distance[ Edge[j].to ] = distance[ Edge[j].from] + Edge[j].value;
                    flag = 1;
                }
            }
        }
    }
    if(flag)
        cout << "possible\n";
    else
        cout << "not possible\n";

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> c;

    while(c--) {
        
        cin >> n >> m;

        for(int i = 0; i < m; ++i) {
            cin >> e.from >> e.to >> e.value;
            Edge.pb(e);
        }

        bellmanFord();

        Edge.clear();

    }
    return 0;
}