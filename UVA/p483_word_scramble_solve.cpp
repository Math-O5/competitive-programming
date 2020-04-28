/******************************************************************************
    483 - Word Scramble
    solve
***********************************************************************/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  map<string, long long int> a, b;
  string s;
  long long int v;
  int n, m, i; 
  cin >> n >> m;
  for(i = 0; i < n; ++i) {
      cin >> s >> v;
      a.insert(make_pair(s,v));
  }
  for(i = 0; i < m; ++i) {
      cin >> s >> v;
      if((int)a[s] < (int)v) {
          a[s] = v;
          if(b.find(s) == b.end()) b.insert(make_pair(s,v));
          else b[s] = v;
      }
  }

  for(map<string, long long int>::iterator it = b.begin(); it != b.end(); it++)
     cout << it->first << " " << it->second << '\n';
return 0;
}
