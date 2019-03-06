#include <map>
#include <stdio.h>
#include <algorithm>

#define MAXN 50

using namespace std;

map<string, int> m;
map<string, int>::iterator per;
int cod[5];

string concatena(){
    char destino[MAXN];
    string ans;
    sprintf(destino,"%d%d%d%d%d",cod[0],cod[1],cod[2],cod[3],cod[4]);
    return ans = destino;
}

int main()
{
    int x;
    while(scanf("%d",&x) && x!=0){
        while(x--){
            for(int i=0;i<5;++i) scanf("%d",&cod[i]);
        
            sort(cod,cod+5);
            string s = concatena();    
            per = m.find(s);
            if(per == m.end()){
                m.insert(make_pair(s,1));
            }
            else {per->second++;}
        }
        int higher = 0, num = 0;
        for(per = m.begin(); per != m.end(); ++per)
            higher = max(higher, per->second);
        
        for(per = m.begin(); per != m.end(); ++per)
            if(higher == per->second) num += higher;
        
        m.clear();
        printf("%d\n",num);
    }
    
    return 0;
}
