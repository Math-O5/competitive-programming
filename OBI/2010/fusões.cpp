#include <bits/stdc++.h>

using namespace std;

int pai[100005];
int peso[100005];

void inicia(int n){
    for(int i = 1; i <= n;i++) pai[i]=i;
}

int find(int x) {
    if(pai[x]==x)return x;
    return pai[x]=find(pai[x]);
}

void join(int x, int y){
    x = find(x); y = find(y);
    if(x==y)return;
    if(peso[x]==peso[y]){pai[x]=y; peso[y]++;}
    if(peso[x]>peso[y])pai[y]=x;
    if(peso[x]<peso[y])pai[x]=y;
}

int main()
{
    int n, k, x, y;
    char c;
    cin >> n >> k; 
    inicia(n);
    while(k--){
        cin>>c>>x>>y;
        if(c=='C'){
            if(find(x)==find(y))cout<<"S"<<endl;    
            else cout<<"N"<<endl;
        }else{
            join(x,y);
        }
        
    }

    return 0;
}
