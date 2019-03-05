#include <set>
#include <iostream>
#include <math.h>

using namespace std;

int n,k, ans, aux, maximum;
int kit[150];
set<int> kitchen;
set<int>::iterator it;

int main(){
    scanf("%d%d",&n,&k);
    for(int i = 0; i <n; ++i){
        scanf("%d",&aux);
        kit[aux]++;
        kitchen.insert(aux);
        maximum = max(maximum,kit[aux]);
    }
    maximum = ceil(maximum/(float)k);
    maximum *= k;
    aux = 0;
    for(it = kitchen.begin(); it!=kitchen.end();++it)
    {
        aux = kit[*it];
        ans += maximum - aux;
    }
    printf("%d\n",ans);
    
    return 0;
}