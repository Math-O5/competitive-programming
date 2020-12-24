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
#define MAXN 120000

const int INF = 0x3f3f3f3f;

int values[MAXN],   // max size n
    arvore[MAXN];   // max size 2^n + 2^(n-1) + ... 1

/**
 *       *[1,4]*           no (1)
 *  *[1,2]*   *[3,4]*     no (2) e (3), respectivamente.
 * 
 */ 
int build(int no, int i, int j) {

    if (i == j) {
        return arvore[no] = values[i];
    } else {
        int meio = (i + j) / 2;
        return arvore[no] = max( build(no*2, i, meio), build(no*2+1, meio+1, j) );
    }

}

// atualiza nó 
void atualiza(int no, int i, int j, int posicao, int novo_valor){ 
	if(posicao < i || posicao > j)
		return;

    if(i == j) { 
		values[posicao] = novo_valor;
		arvore[no] = values[i];
	} else {	
		int esquerda = 2*no;   
		int direita  = 2*no + 1;
		int meio = (i + j)/2;
		
        atualiza(esquerda, i, meio, posicao, novo_valor);
        atualiza(direita, meio+1, j, posicao, novo_valor);
		
		arvore[no] = max(arvore[esquerda], arvore[direita]);
	}
	return;  
}

// A, B é a query
// i, j é o intervalo atual
int consulta(int no, int i, int j, int A, int B){
	
	if(A <= i && j <= B) { 
		return arvore[no];
	}
	
	if(i > B || A > j) { 
		return -INF;
	}
	
	int esquerda = 2*no;     
	int direita  = 2*no + 1; 
	int meio = (i + j)/2;
	
    return max(consulta(esquerda, i, meio, A, B),
				consulta(direita, meio+1, j, A, B));
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int n, q, a, b;

    cin >> n >> q;
	for(int i = 0; i < 2*n; ++i) {
		cin >> a >> b;
        values[i] = b - a;
	} 

	build(1, 0, n-1);

	for(int i = 0; i < 10; ++i) 
        cout << arvore[i] << ' ';
    cout << endl;
    return 0;
}

