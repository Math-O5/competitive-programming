//When 10^8 * 10^8 = 10^16
#include <iostream>

using namespace std;

long long int mdc(long long int x,long long int y){
    return (y==0? x : mdc(y,x%y));
}
int main()
{
    long long int a, b, c, d;
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    // a/b + c/d = (a*d + c*b)/ b*d
    a = (a*d + c*b);
    b = (b*d);
    while((c = mdc(a,b)) != 1){
        a /= c; b /= c;    
    }
    printf("%lld %lld\n",a,b);
    return 0;
}
