#include<iostream>
#include <algorithm>
#include<vector>

using namespace std;

struct consultas {
       int id;
};
int main () {
 int n, k, transf;
 cin >> n;
 vector<int> pessoas;
 for(int i=0;i<n;++i) {
     cin >> transf;
     pessoas.push_back(transf);
 }
cin >> k;
   for(int i=0;i<k;++i) {
       cin >> transf;
       for(int j=0;j<n;++j) {
            if(pessoas[j]==transf) {
                pessoas.erase(pessoas.begin()+j);
                break;
            }
   }
 }
 for(int i=0;i<n-k;++i) {
     cout << pessoas[i] << " ";
 }
return 0;
}
