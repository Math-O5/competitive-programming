// LIS - Longest Increase Sequence
// https://en.wikipedia.org/wiki/Patience_sorting
// https://olimpiada.ic.unicamp.br/pratique/p1/2014/f1/letra/
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h> // memset
#include <algorithm> // lower_bound

using namespace std;

#define fs first
#define sd second
#define pb push_back

const int INF = 0x3f3f3f3f;

int n, aux;
vector<int> topo;
string s;

int parseInt(char c) {
    return int(c - '0');
}

// distribution of numbers in stacks such that: Put the number in the leftmost stack that the number is greater o euqla
// that the number. If there1s not, create a stack in the rightmost side.
// The number os stack is the length of LIS.
//  -7 10 9 2 3 8 8 1
// stack one:   -7
// stack two:    1 2 9 10
// stack three:  3
// stack four:   8 8
// O (nlogn) time
void lis() {
    topo.pb(parseInt(s[0]));
    vector<int>::iterator it;

    n = (int)s.size();

    for(int i = 1; i < n; ++i) {
        it = upper_bound(topo.begin(), topo.end(), parseInt(s[i]));
        if(it == topo.end())
            topo.pb(parseInt(s[i]));
        else
            *it = parseInt(s[i]);        
    }

    cout << topo.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> s;
    
    lis();
    return 0;
}