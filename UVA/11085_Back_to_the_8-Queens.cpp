#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<string.h>

using namespace std;

bool valid(int col[], int lin[], int x, int y)
{
    if(col[x] != -1 || lin[y] != -1)
        return false;

    int h, l;
    for(int i = 0; i < x; ++i)
    {
        if(col[i] != -1) {
            h = x - i;
            for(int j = 0; j < y; ++j)
            {
                if(lin[j]!=-1) {
                    l = y - i;
                    if(l == h) // se a altura de distancia entre a rinha atual e a prev são igual, simultaneamente à largura, então estão na diagonal;
                        return false;
                }
            }
        }
    }
    cout << "aaaa\n";
    return true;
}

void backtracking(int col[], int lin[], int column) 
{
    for(int i = 0; i < 8; ++i)
    {
        if(valid(col, lin, column, i)) 
        {
            col[column] = i;
            lin[i] = column;
            if(column < 7)
                backtracking(col, lin, column + 1); 
            else
            {
                cout << "bbbbb";
                for(int j = 0; j < 8; ++j)
                {
                    cout << col[j] << ' ' << lin[j] << endl;
                }
                return;
            }
        }
        //lin[i] = -1;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int col[8], lin [8];
    memset(col, -1, 8*sizeof(int));
    memset(lin, -1, 8*sizeof(int));
    backtracking(col, lin, 0); 
    return 0;
}