#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

char grid[MAX][MAX];
int visited[MAX][MAX];
string line; 

int ans[8]; //sardines, mackerels, salmons, turtles, groupers, dolphins, whales and sharks.

int n, l, c; // cases n, lines and columns

void classify(int w, int h) {
    if(w == 1 && h == 1)
        ans[0]++;
        
    else if((w == 2 && h == 1) || (w == 1 && h == 2) )
        ans[1]++;

    else if((w==1 && h > 2)||(w>2 && h==1))
        ans[2]++;
    
    else if(w == h) {
        ans[3]++;
    }
}

//verify if is valid position and if it is part of the animal
int validPos(int i, int j, char letter) {
    if((i >= 0 && i < l) && (l >= 0 && l< c) && visited[i][j]==0 && letter==grid[i][j])
        return visited[i][j] = 1; 
    return 0;
}

// verify which animal is more problably to be
void AnimalsMap(int i, int j) {
    int w = 0, h = 0, i1 = i, j1 = j;
    char letter = grid[i][j];

    while(validPos(i1, j, letter)) {
        h++;
        i1++;
    }
    
    while(validPos(i, j1++, letter)) {
        w++;
    }
    
    for(i; i <= i1; ++i) 
        for(j; j <= j1; ++j)
            visited[i][j] = 1;
            
    classify(w, h);
    
}

// go through the sea
void seaInspetion() {
     
    for(int i = 0; i < l; ++i) {
        for(int j = 0; j < c; ++j) {
            if(visited[i][j] == 0 && grid[i][j] != '.') {
                AnimalsMap(i, j);
            }
        }
    } 
}

void printAns() {
    for(int i = 0; i < 8; ++i) 
        printf("%d ", ans[i]);
    printf("\n");
}

int main()
{
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; ++i) {
        
        getline(cin, line);
        
        scanf("%d %d", &l, &c);
        for(int l1 = 0; l1 < l; ++l1) {
            getchar();
            scanf("%[^\n]s", &(grid[l1][0]));
        }
        
        seaInspetion();
    }

    printAns();
    
    return 0;
}
