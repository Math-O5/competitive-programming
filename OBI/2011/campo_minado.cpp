/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int campo[n];
    int minas[50]= {0};
    for(int i = 0; i < n; ++i) 
    {
        cin >> campo[i];
        minas[i] = campo[i];
        
    }
    for(int i = 0; i < n; ++i) 
    {
        if(campo[i-1]==1 && i-1>=0) ++minas[i];
        if(campo[i+1]==1 && i+1<n) ++minas[i];
        
    }
    
    for(int i = 0 ; i< n; ++i) cout<<minas[i] << "\n";

    return 0;
}
