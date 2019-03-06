#include <iostream>

using namespace std;

long long int mdc(long long int n,long long int m){
    return (m==0? n : mdc(m,n%m));
}

int main(){
    long long int n,m, ans;
    cin>>n>>m;
    while((ans = mdc(n,m)) > 1){
        (--m);
    }
    cout <<m<<endl;
    return 0;
}