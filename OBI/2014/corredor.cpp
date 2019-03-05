#include<bits/stdc++.h>

using namespace std;

int s[50005];
int n;

int maior(int n)
{
    int resp=0, maior=0;
	
	for(int i=0;i<n;i++){
		
		maior=max(0,maior+s[i]);
		
		resp=max(resp,maior);
	}
	
	return resp;
}


int main() 
{
    int n;
    cin >> n;
    
    int i;
    for(i =0; i < n; ++i) 
    {
       cin >> s[i];   
    }
    
    cout << maior(n);
    
    return 0;
}