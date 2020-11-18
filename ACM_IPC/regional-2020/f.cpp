#include<bits/stdc++.h>

using namespace std;

char c;
bool isTurn;
int plac[2], vic[2];  

int someone_gain() {
    if(plac[0] == 10 || (plac[0] >= 5 && (plac[0]-plac[1])>= 2))
        return 1;
    if(plac[1] == 10 || (plac[1] >= 5 && (plac[1]-plac[0])>= 2))
        return 2;
    return 0;
}

int main() {
    isTurn = 0;
    int endgame = 0;
    while(scanf("%c", &c), c != '\n') {
        if(c == 'S') {
            plac[isTurn]++;
        } else if(c == 'R') {
            isTurn = !isTurn;
            plac[isTurn]++;
        } else {
            //show plac
            printf("%d ", vic[0]);
            if(endgame == 2 && vic[1]==2) {
                printf("- %d (winner)\n", vic[1]);
            } else if(endgame == 1 && vic[0]==2) {
                printf("(winner) - %d\n", vic[1]);
            } else {
                printf("(%d", plac[0]);
                if(isTurn==0) {
                    printf("*");
                }
                printf(") - %d (%d", vic[1], plac[1]);
                if(isTurn) {
                    printf("*");
                }
                printf(")\n");
            }

        }
        endgame = someone_gain();
        if(endgame > 0) {
            vic[endgame-1]++;
            isTurn = endgame-1;
            plac[0] = 0;
            plac[1] = 0;
        }
    }
    return 0;
}
