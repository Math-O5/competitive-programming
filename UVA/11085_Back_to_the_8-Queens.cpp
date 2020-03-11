#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<string.h>
#define MAX 100000

using namespace std;

int queen[8], tab[8];

bool valid(int column)
{
    for(int i = 0; i < column; ++i)
    {
        if(tab[column]==tab[i] ||
            (abs(tab[column] - tab[i]) == abs(i - column)))
            return false;
    }
    return true;
}

int backtracking(int column) 
{   
    if(column == 8)
        return 0;
    int resp = MAX;
    for(int i = 0; i < 8; ++i)
    {
        tab[column] = i;
        if(valid(column))
        {
            int respMove = (queen[column]!=i+1)? 1 + backtracking(column+1) : backtracking(column+1);
            resp = min(resp, respMove);
        }
    }
    return resp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int i = 0, j = 0;
    while(cin >> queen[i]) {
        if(i == 7) {
            cout << "Case " << ++j << ": " << backtracking(0) << '\n'; 
            i = -1;
        }
        ++i;
    }
    return 0;
}