/*
    0 <= N < 10^1000000

    Proof of criterios: 
    a % 4 = (a0*10^0 + ... + an*10^n) % 4 = (a0*10^0 + a1*10^1) % 4 = (a0 + a1*10) % 4
    a % 3 = (a0*10^0 + ... + an*10^n) % 9 = (a0*1 + a1*1 + ... + an*1) % 9
    a % 5 = (a0*10^0 + ... + an*10^n) % 25 = (a0*10^0 + a1*10^1) % 25 = a0 + a1*10 % 25
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
        sum = (sum + toNumber(v))%9;
    }
    
    if(s.size() >= 2 && (((toNumber(s[s.size()-2])*10 + toNumber(s[s.size()-1]))%4) == 0)) {
        cout << "S\n";
    }
    else if(s.size() < 2 && toNumber(s[s.size()-1]) % 4 == 0) {
    	cout << "S\n";
    } else {
    	cout << "N\n";
    }
    
    if(sum % 9 == 0) {
    	cout << "S\n";
    } else {
    	cout << "N\n";
    }
    
    if(s.size() >= 2 && (((toNumber(s[s.size()-2])*10)+toNumber(s[s.size()-1])) % 25 == 0) ) {
    	cout << "S\n";
    } else if(s.size() < 2 && toNumber(s[s.size()-1]) == 0) {
    	cout << "S\n";
    }
    else {
    	cout << "N\n";
    }
    return 0;
}