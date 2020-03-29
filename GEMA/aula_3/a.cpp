#include<stdio.h>
int main () {
int a,b,n;
scanf("%d%d",&a,&b);
n= 1;
while(a<=b) {
    b = (b*2*n);
    a = (a*3*n);
    if (a<=b) {
    n = n + 1;
    }
   }
  printf("%d",n);
}