#include <iostream>
#include <string>
#include <set>

using namespace std;
set <int> S;
set<int> S1;
set<int> aux;
int main()
{
    int n, n1, m;
    cin >> n >> n1;
    while(n--) {
        cin >> m;
        S.insert(m);         
    }
    while(n1--) {
        cin >> m;
        if(S.find(m) != S.end() || aux.find(m) != aux.end()) { S.erase(m); aux.insert(m); }
        else S1.insert(m);
    }
    int a, b;
    a = S.size(); b = S1.size();
    cout << ((a < b)? a : b) << endl;
  return 0;
}
