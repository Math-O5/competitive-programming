/*
    0 <= N < 10^1000000

    Proof of criterios: 
    a % 2 = (a0*10^0 + ... + an*10^n) % 2 = (a0*10^0) % 2 = a0 % 2
    a % 3 = (a0*10^0 + ... + an*10^n) % 3 = (a0*1 + a1*1 + ... + an*1) % 3
    a % 5 = (a0*10^0 + ... + an*10^n) % 5 = (a0*10^0) % 5 = a0 % 5
*/
#include<iostream>
#include<string>
using namespace std;

string s;
int sum = 0;

int toNumber(char c) {
    return int(c-'0');
}

int main() {
    cin >> s;
    
    for(auto v : s) {
        sum = (sum + toNumber(v))%3;
    }
    
    if(toNumber(s[s.size()-1]) % 2 == 0) {
    	cout << "S\n";
    } else {
    	cout << "N\n";
    }
    if(sum % 3 == 0) {
    	cout << "S\n";
    } else {
    	cout << "N\n";
    }
    if(toNumber(s[s.size()-1]) % 5 == 0) {
    	cout << "S\n";
    } else {
    	cout << "N\n";
    }
    return 0;
}