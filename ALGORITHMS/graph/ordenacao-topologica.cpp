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

    for(int i = 1; i <= n; ++i) {
        if(!grau[i]) {
            orderedTop.push_back(i);
        }
    }

    int index = 0;
    while(index < (int)orderedTop.size()){

		int atual = orderedTop[index];
		index++;
		
		for(int i = 0;i < (int)grafo[atual].size(); ++i){
			int v = grafo[atual][i];
			grau[v]--;
			if(grau[v] == 0) orderedTop.push_back(v); // se o grau se tornar zero, acrescenta-se a lista
		}
	}
	if((int)orderedTop.size() < n)
        cout << "impossivel\n";

	else {
		for(int i = 0;i < (int)orderedTop.size(); ++i) 
            cout << orderedTop[i] << " ";
		cout << endl;
	}

    return 0;
}