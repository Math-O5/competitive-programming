#include<stdio.h>

int main() {
    int mid, ans, ini = 1, fim = 10;
    while(1) {
        mid = ( ini + fim ) / 2;
        printf("%d\n", mid);
        fflush(stdout);
        scanf("%d", &ans);

        if(ans == 2) {
            return 0;
        } else if(ans == 0) {
            fim = mid - 1;
        } else {
            ini = mid + 1;
        }
    }
    return 0;
}