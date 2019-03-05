#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>  pq;
int qtd[1020];

int main(){
    
    int n, l, aux=0;
    scanf("%d%d",&n,&l);
    int i=1;
    while(l--){
        if(i<=n){pq.push(make_pair(0,i));++i;}
        scanf("%d",&aux);
        pair<int,int> m = pq.top();
        pq.pop();
        m.first += aux;
        qtd[m.second]++;
        pq.push(make_pair(m.first,m.second));
    }
    for(i=1;i<=n;++i)cout<<i<<' '<<qtd[i]<<endl;
    return 0;
}