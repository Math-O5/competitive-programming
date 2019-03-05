#include <bits/stdc++.h>

using namespace std;

struct aero
{
    int id=0;
    int cont=0;
};
bool comp(aero a, aero b)
{
    if(a.cont==b.cont) {
        return a.id<b.id;
    }
    return a.cont>b.cont;
    
}
int main()
{
    int a=1,v=1, x,y,i=1;
    while(a!=0 && v!=0)
    {
       cin>> a >> v;
       if(a==0 && v==0) break;
       aero voo[a];
       for(int i=1;i<=a;++i) 
       {
           voo[i-1].id =i;
       }
       for(int i=0;i<v;++i) 
       {
           cin >> x >> y;
           voo[x-1].cont +=1;
           voo[y-1].cont +=1;

       }
       int k=0;
       sort(voo,voo+a,comp);
       cout<<"Teste"<<" "<< i << "\n" << voo[0].id;
       while(voo[k].cont==voo[k+1].cont) {
             cout<<" "<< voo[k+1].id;
             k++;
       }
       i++;
    }

    return 0;
}