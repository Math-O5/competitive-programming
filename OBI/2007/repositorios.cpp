#include <iostream>
#include<set>
#include<map>
using namespace std;
#define MAXN 1000
#define E int
map<int, int> prog;
set<int> ordem;
int main(){
   int x, y, m ,n;
   cin>>x>>y;
   while(x--) {cin>>m>>n; prog[m]=n; }
   while(y--) {cin>>m>>n; if(prog[m]<n){ prog[m] = n; ordem.insert(m);} }
   for(set<int>::iterator it = ordem.begin(); it!=ordem.end();++it)
    {
        cout << (*it) << ' ' << prog[(*it)] << endl;
    }
   
    return 0;
}