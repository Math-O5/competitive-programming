#include <iostream>
#include <algorithm>

#define MAXN 200005
using namespace std;

int array[MAXN];
int n, i, ans, maximum, aux;

int main() {
    ans=1;
    cin >> n;
    for(i=1;i<=n;++i){
        cin >> array[i];
    }
    char s[MAXN];
    cin >> s;
    for(i=1; i<=n;++i){
        maximum = max(maximum, array[i]);
        if(maximum>i && (s[i-1]-'0')!=1){cout << "NO" << endl; return 0;}
    }
    cout << "YES" << endl;

    return 0;
}