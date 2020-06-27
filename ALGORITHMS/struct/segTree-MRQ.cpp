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
        return arvore[no] = i;
    } else {
        int meio = (i + j) / 2;
        return arvore[no] = min( build(no*2, i, meio), build(no*2+1, meio+1, j) );
    }

}

void atualiza(int no, int i, int j, int posicao, int novo_valor){ 
	
    if(i == j) { 
		arvore[no] = i;
		values[posicao] = novo_valor;
	} else {	
		int esquerda = 2*no;   
		int direita  = 2*no + 1;
		int meio = (i + j)/2;
		
		if(posicao <= meio) 
            atualiza(esquerda, i, meio, posicao, novo_valor);
		else 
            atualiza(direita, meio+1, j, posicao, novo_valor);
		
		if( values[ arvore[esquerda] ] < values[ arvore[direita] ] )
            arvore[no] = arvore[esquerda];
		else arvore[no] = arvore[direita];
	}

}

int consulta(int no, int i, int j, int A, int B){
	
	if(A <= i && j <= B) { 
		return arvore[no];
	}
	
	if(i > B || A > j) { 
		return -1;
	}
	
	int esquerda = 2*no;     
	int direita  = 2*no + 1; 
	int meio = (i + j)/2;
	
    int resposta_esquerda = consulta(esquerda, i, meio, A, B);
	int resposta_direita  = consulta(direita, meio+1, j, A, B);
	
	if(resposta_esquerda == -1) 
        return resposta_direita;  
	if(resposta_direita == -1) 
        return resposta_esquerda;
	
	if(values[resposta_esquerda] < values[resposta_direita]) 
        return resposta_esquerda;
	else return resposta_direita;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    return 0;
}

