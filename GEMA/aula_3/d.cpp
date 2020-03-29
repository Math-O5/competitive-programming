#include <stdio.h>
 
int main () {
   int n,p=0;
   scanf("%d\n",&n);
   int v[n];
  for (int m=1; m<=n;m++) {
    scanf("%d",&v[m]);
    if (v[m]>0 && v[m]%2==0) {
        p++;
    }
    else if (v[m]<0 && v[m]%2==0) {
        p++;
    }
  }
printf("%d",p);
return 0;
}