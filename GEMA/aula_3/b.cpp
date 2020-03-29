#include<stdio.h>
int main () {
    int n,m,M=0;
    scanf("%d",&n);
    int v[n];
    for(int i=1;i<=n;++i) {
      scanf("%d",&v[i]);
    }
    m = v[1];
    for(int i=1;i<=n;++i) {
        if(v[i]>M){
        M=0;
        M=v[i];
      }
        if(v[i]<m) {
        m=0;
        m = v[i];
        }
    }
printf("%d",M-m);
return 0;
 
}