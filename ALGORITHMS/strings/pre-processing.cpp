#include<iostream>
#include<string>

#define MAXN 500005

using namespace std;

void kmpProcess(int *aux, const string& pat, int n) {
    int i = 0, j = -1;
    aux[0] = -1;

    while(i < n) {
        while(j >= 0 and pat[i] != pat[j]) {
            j = aux[j];
        }
        ++i; ++j;
        aux[i] = j;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int aux[MAXN];
    string pat;
    int n, m, t;
    cin >> t;
    for(int j = 0; j < t; ++j) {
        cin >> pat >> m;
        n = (int)pat.size();
        kmpProcess(aux, pat, n);
        int f =  aux[n];
        // cout << f << endl;
        // f = (f == 0)? n : f;
        cout << (n + ((n-f)*(m-1))) << endl; 
        // for(int i = 0; i < n+1; ++i)
        //     printf("%d", aux[i]);
        // cout << endl;
    }

    return 0;
}