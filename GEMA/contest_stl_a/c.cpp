#include<iostream>
#define MAX 1000000
using namespace std;
 
int n, m;
int a[MAX], b[MAX], inia,inib;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    cin >> m;
    if(m > n)
    {
        cout << "N\n";
        return 0;
    }
    for(int i = 0; i < m; ++i)
    {
        cin >> b[i];
    }
    
    int last = 1;
    while(inia < n && inib < m)
    {
        if(a[inia]==b[inib])
        {
            ++inia; ++inib;
            continue;
        }    
        inib = 0;
        inia = last;
        ++last;
    }
    
    if(inib==m)
        cout << "S\n";
    else
        cout << "N\n";
    return 0;
}