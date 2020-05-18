#include <bits/stdc++.h>
#define MAXN 100500
using namespace std;

int jogadores[MAXN];
int pontos[MAXN];
int peso[MAXN];

int find(int x){
    if(jogadores[x]==x)return x;
    return jogadores[x]=find(jogadores[x]);
}

void join(int x, int y){
    x = find(x); y = find(y);
    if(x == y) return;    
    if(peso[x]>peso[y]){
        jogadores[x] = y;
        pontos[y] += pontos[x];
        peso[x]++;
    }
    else {
        jogadores[y] = x;
        pontos[x] += pontos[y];
        peso[y]++;
    }
}

int fight(int a, int b){
    int x = find(1);
    a = find(a); b = find(b);
    if (a==x && pontos[a]>pontos[b]) return 1;
    if (b==x && pontos[b]>pontos[a]) return 1;
    return 0;
}

int main(){
    int n, m, q, a, b, ans, i;
    while(scanf("%d%d",&n,&m) && (n!=0 || m!=0)){
        ans = 0;
        for(i = 1;i<=n;++i) scanf("%d",&pontos[i]);
        for(i = 1;i<=n;++i) {jogadores[i] = i; peso[i]=0;}
        for(i = 0;i<m;++i){
            scanf("%d%d%d",&q,&a,&b);
            if(q==1)join(a,b);
            else if(fight(a,b)==1)++ans; 
        }
        printf("%d\n",ans);
    }
    return 0;
}
