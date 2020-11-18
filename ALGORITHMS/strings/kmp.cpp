#include<bits/stdc++.h>
#define MAXN 1000010

using namespace std;

void kmpProcess(int *aux, string pat, int n) {
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

void kmpSearch(int *aux, string pat, string text, int n, int n_text) {
    int i = 0, j = 0, sol[n_text], found = 0;
    while(i < n_text) {
        while(j >= 0 && text[i] != pat[j]) {
            j = aux[j];
        }
        ++i; ++j;
        if(j == n) {
            sol[found] = i - j +  1;
            found++;
            j = aux[j];
        }
    }
    if(!found) {
        printf("Not Found\n\n");
    } else {
        printf("%d\n", found);
        for(int i = 0; i < found; ++i) {
            printf("%d ", sol[i]);
        }
        printf("\n\n");
    }
}

int main() {
    int aux[MAXN];
    string pat, text;
    int n, m, t;
    cin >> t;
    for(int j = 0; j < t; ++j) {
        cin >> text >> pat;
        m = (int)text.size();
        n = (int)pat.size();
        kmpProcess(aux, pat, n);
        kmpSearch(aux, pat, text, n, m);
    }

    return 0;
}