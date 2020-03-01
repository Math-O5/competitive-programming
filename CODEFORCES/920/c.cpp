#include<iostream>
#include<vector>
#define MAX 200003

using namespace std;

int sorted[MAX], n, pai[MAX];
//vector<char> canSwap;
char aux;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> sorted[i];
        pai[i]=i;
    }
    for(int i = 1; i < n ; ++i)
    {
        cin >> aux;
        //canSwap.push_back(aux);
        if(aux=='1')
            pai[i+1]=pai[i];
    }

    for(int i = 1; i < n; ++i)
    {    
        if(sorted[i]>i && pai[i]!=pai[sorted[i]])
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}