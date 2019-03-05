#include<iostream>
#include <algorithm>
using namespace std;

struct times {
       int id=0, ouro=0, prata=0, bronze=0;
};
int comp(times A, times B) {
    if(A.ouro != B.ouro) return A.ouro<B.ouro;
    if(A.prata != B.prata) return A.prata<B.prata;
    if(A.bronze != B.bronze) return A.bronze<B.bronze;
    if(A.id!=B.id) return A.id>B.id;
}

int main () {
 int n,m,j;
 cin >> n >> m;
 int placar;
 times todos[101];
 for(int i=0;i<n;++i) {
    todos[i].id=i+1;
 }
  for(int i=0;i<m;++i) {
         cin >> placar;
         todos[placar-1].ouro++;
         cin >> placar;
         todos[placar-1].prata++;
         cin >> placar;
         todos[placar-1].bronze++;
     }
   sort(todos, todos+n, comp);
  for(int i=n-1;i>=0;--i) {
    cout << todos[i].id << " ";
 }

return 0;
}
