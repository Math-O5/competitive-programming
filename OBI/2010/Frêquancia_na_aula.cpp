#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    set<int> S;
    int n,m, ans = 0;
    cin >> n;
    while(n--) {
        cin >> m;
        if(S.find(m) == S.end()) { S.insert(m); ans++; }         
    }
    cout << ans << endl;
    
  return 0;
}