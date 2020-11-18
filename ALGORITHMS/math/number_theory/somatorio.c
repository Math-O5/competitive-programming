#include<stdio.h>

#define MAXN 100000

int somatorio(int n, int* acumulador) {
    if(n == 0) {
        return acumulador[n]; 
    }
    return acumulador[n] + somatorio(n-1, acumulador);
}

int main() {
    int n, acumulador[MAXN];

    printf("Digite um número inteiro n: ");
    scanf("%d", &n);
    
    for(int i = 0; i < n; ++i) {
        printf("Entre um número: ");
        scanf("%d", &acumulador[i]);
    }

    printf("A soma total é %d\n", somatorio(n, acumulador-1));
    return 0;
}