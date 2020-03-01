#include <bits/stdc++.h>

using namespace std;

int realNumber(char c) {
    if(c >= 'A' && c <= 'Z')
        return int(c - 'A');
    else if(c >= 'a' && c <= 'z')
        return int(c - 'a');
    return -1;
}

bool stringNoRepetion2(string s) {
    if(s.size() > 26) {
        return false;
    }

    int check = 0;
    for(int i = 0; i < s.size(); ++i) {
        int digit = realNumber(s[i]); 
        if((check & (1 << digit)) > 0)
            return false;
        check |= (1 << digit);
    }
    return true;  
}

bool stringNoRepetion(string s) {
    
    if(s.size() > 26 )
        return false;

    int freq[26];

    memset(freq, 0, 26*sizeof(int));

    for(int i = 0; i < s.size(); ++i) {
        int digit = realNumber(s[i]); 
        if(digit != -1 && freq[digit] == 0)
            freq[digit]++;
        else
            return false;
    }
    return true;
}

int main() {
    cout << stringNoRepetion("sahjkilo");
    cout << stringNoRepetion2("sahjkilo");
    return 0;
}