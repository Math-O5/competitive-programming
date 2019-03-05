#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main () {
  int n, transf, cont=0;
  cin >> n;
  int v[n], v2[n], v3[n];
  for(int i=0;i<n;++i) {
      cin >>  transf;
      v[i] = transf;
      v2[i]= transf;
  }
  sort(v,v+n);
  for(int i=0;i<n;++i) {
      if(v[i]!=v2[i]) {
        v3[cont]=v[i];
        cont++;
      }
  }
  cout << cont << endl;
  for(int i=0;i<cont;++i) cout << v3[i] << " ";

return 0;
}

