#include <iostream>
#include <string>
#include <math.h>

#define M 5
#define N 20

using namespace std;

string s;

int a, b, c, aux;
/*
    (m,n) => [a][b] = a*n + b
    45/20 == 3 (a)
    45/3 == 15 (b)
    
    44/20 == 3 
    44/3 == 15
    
    
    20/20 == 1
    20/1 == 20
    
    21/20 == 2
    21/2 == 11

*/
int j,i,at;
int main(){
    cin>>s;
    aux = s.size();
    a = ceil(aux/(float)N);
    b = ceil(aux/(float)a);
    c = a*b - aux;
    cout << a << ' ' << b<<endl;
    for(i=0;i<a;++i){
        for(j=0; j<b;++j) {
            if(((i*b+j)%b==0)&& c){cout<<'*'; at++;--c;}
            else cout<<s[i*b+j-at];
        }
        cout << endl;
    }
    return 0;
}