#include<iostream>
#include <algorithm>
using namespace std;

int main () {
  int n, m, cont=0;
  cin >> n >> m;
  pair<int,int> v[n];
  for(int i=0;i<n;++i){
   v[i].first = 0;
   v[i].second = 0;
  }
  for(int i=0;i<n;++i){
      for(int j=0;j<m;++j) {
          cin >> cont;
          v[i].first += cont;
      }
      v[i].second = i+1;
  }
  sort(v,v+n); //Ordena do menor para o menor.
  for(int i=0;i<3;++i) {
      cout << v[i].second << endl;
  }
return 0;

}
