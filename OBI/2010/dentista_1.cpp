#include<iostream>
#include <algorithm>
using namespace std;

struct consultas {
       int ini, fim;
};
int comp(consultas A, consultas B) {
    if(A.fim < B.fim) return 1;
    else return 1;
}

int main () {
 int n, cont=1;
 cin >> n;
 consultas x[n];
 for(int i=0;i<n;++i) {
     cin >> x[i].ini >> x[i].fim;
 }
 for(int i=0;i<n-1;++i) {
     if(x[i].fim>x[i+1].ini){
        if(x[i].fim>x[i+1].fim) {
           continue;
        } else x[i+1]= x[i];
     } else cont++;

//   sort(todos, todos+n, comp);
//  for(int i=n-1;i>=0;--i) {
 }
  cout << cont;
return 0;
}
