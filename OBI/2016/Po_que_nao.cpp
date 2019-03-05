#include<iostream>
#include <algorithm>
using namespace std;

int main () {
  int n,v[3], cont=0;
  cin >> n >> v[0] >> v[1] >> v[2];
  sort(v,v+3);
  if(n-v[0]>=0) {
    n=n-v[0];
    cont++;
  }
  if(n-v[1]>=0) {
    n=n-v[1];
    cont++;
  }
  if(n-v[2]>=0) {
    cont++;
  }
  cout << cont;
return 0;
}