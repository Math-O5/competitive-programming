#include <algorithm>
#include<bits/stdc++.h>


using namespace std;

// defino MAXN como 1010
#define MAXN 1010

// declaro as variC!veis que vou usar
int s1[MAXN], s2[MAXN], tab[MAXN][MAXN];
int n,m;

int lcs(int a, int b){ // declaro a funC'C#o da DP, de nome lcs
	
	// se jC! calculamos esse estado da dp antes
	if(tab[a][b]>=0) return tab[a][b]; // retornamos o valor salvo para ele
	
	// se uma das sequC*ncias for vazia, retornamos zero
	if(a==0 or b==0) return tab[a][b]=0;
	
	// se s1[a] for igual a s2[b], os retiramos das sequC*ncias
	if(s1[a]==s2[b]) return 1+lcs(a-1, b-1); // e adicionamos ele C  lcs das subsequC"ncias restantes
	
	// se forem diferentes, retorno o mC!ximo entre retirar s1[a] ou s1[b]
	return tab[a][b]=max(lcs(a-1, b), lcs(a, b-1));
}

int main()
{
    
    for(int i = 0; i < MAXN; ++i) 
    {
        for(int j = 0; j < MAXN; ++j)
        {
            tab[i][j] = -1;
        }
    }
    
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        cin >> s1[i];
    }
      for(int i = 1; i <= m; ++i)
    {
        cin >> s2[i];
    }
    int resp = lcs(n,m);
    
    cout << n- resp << " " << m - resp << '\n';
    
    
    return 0;
}