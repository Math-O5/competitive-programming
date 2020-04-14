 
#include<iostream>
#define MAX 1000000
using namespace std;

char trem[MAX];

int i, pontos;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(cin >> trem[++i])
    {
        if(trem[i] < 'a')
        {
            pontos -= 100;
            continue;
        }

        int j = i-1;
        while(j > 0)
        {
            if(trem[j] < 'a')
            {
                if(trem[j]==trem[i]-32)
                    pontos += 200;
                else
                    pontos -= 100;
                trem[j] += 32;
                break;
            }
            --j;
        }
        if(j == 0) pontos -= 300;
    }
    
    cout << pontos << '\n';
    return 0;
}/*  */