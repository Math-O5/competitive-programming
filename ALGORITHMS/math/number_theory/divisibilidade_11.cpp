/*
    0 <= N < 10^1000000

    Proof of criterios: 
    a % 11 = (a0*10^0 + ... + an*10^n) % 11 =
    (a0*1 + a1*(-1) + a2*1 + a3*(-1) + ... an*(-1^n) ) % 11 = 
    a0 - a1 + a2 - ... + an*(-1)^n =
    sum (ai * (-1)^i ) % 11 == 0
*/

#include<iostream>
#include<string>
using namespace std;

string s;
long long int sumPar = 0, sumImpar = 0;

int toNumber(char c) {
    return int(c-'0');
}

int main() {
    cin >> s;
    int n = 0;
    for(auto v : s) {
        if(n) {
            sumPar += toNumber(v);
        } else {
            sumImpar += toNumber(v);
        }
        
        n = (n+1)%2;
    }
    
    
    if(sumPar - sumImpar == 0) {
    	cout << "S\n";
    } else {
    	cout << "N\n";
    }
    
 
    return 0;
}