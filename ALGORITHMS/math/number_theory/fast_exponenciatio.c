#include<stdio.h>

double fast_exp(double base, int expo) {
    if(expo == 0) {
        return 1;
    } else if(expo == 1) {
        return base;
    }

    double f = fast_exp(base, expo/2);
    f = f*f;

    if(expo % 2 == 0) {
        return f;
    } else {
        return base * f;
    }
}

int main() {
    double base;
    int expo;

    printf("Digete um expoente(inteiro): ");
    scanf("%d", &expo);
    printf("Digite a base: ");
    scanf("%lf", &base);

    printf("O valor é: %lf", fast_exp(base, expo));
    return 0; 
}