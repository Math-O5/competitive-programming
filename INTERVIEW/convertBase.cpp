 #include <bits/stdc++.h>

 using namespace std;

 int power(int base, int index) {
     int ans = 1;
     for(int i = 0; i < index; ++i) {
         ans *= base;
     }
     return ans;
 }

 int digitToValue(char digit) {
     if(digit >= '0' && digit <= '9')
         return int(digit - '0');
     else if (digit >= 'A' && digit <= 'Z')
         return 10 + int(digit - 'A'); // a is equal 10, b is equal 11 and so on.
     else if(digit >= 'a' && digit <= 'z')
         return 10 + int(digit - 'a');
     else {
         return -1;
     }
 }

 //Input number is given as string and output is an integer.
 //Input: str = "1100", base = 2 
 //Output: 12
 int convertToBase(string number, int base) {
    int value = 0;

    if(base < 1)
        return -1;
    for(int i = number.size() - 1; i >= 0; --i) {
        int digit = digitToValue(number[i]);
        int exp = number.size() - 1 - i;

        if(digit >= base)
            return -1;
            
        value += digit * power(base, exp);
    }
    return value;
 }

 int main() {
     int base;
     string number;
     cin >> base >> number;
     cout << convertToBase(number, base) << endl;
     return 0;
 }