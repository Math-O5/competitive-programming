// LIS - Longest Increase Sequence
// https://en.wikipedia.org/wiki/Patience_sorting
// https://neps.academy/lesson/163
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
vector<int> numbers;

void lis() {
    topo.pb(numbers[0]);
    vector<int>::iterator it;

    for(int i = 1; i < n; ++i) {
        it = lower_bound(topo.begin(), topo.end(), numbers[i]);
        if(it == topo.end())
            topo.pb(numbers[i]);
        else
            *it = numbers[i];        
    }

    cout << topo.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n;
    
    for(int i = 0; i < n; ++i) {
        cin >> aux;
        numbers.pb(aux);
    }   
    return 0;
}