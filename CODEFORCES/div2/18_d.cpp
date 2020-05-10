// https://codeforces.com/blog/entry/16380
#include <iostream>
#include<string>
#include<vector>
#include<string.h>

using namespace std;

const int base = 1e9;
typedef vector<int> Bigint;

long long int win[2050];

// Erase zeros from back
void Set(Bigint &a) {
    while(a.size() > 1 && a.back() == 0) 
        a.pop_back();
}

// number = 1098
// set string 8901
// return 
Bigint Integer(string s) {
    Bigint ans;

    // Check if it is empty
    if(s.size() == 0) {
        ans.push_back(0); 
        return ans;
    }

    if(s[0] == '-')
        return ans;
    
    // start : 8901 size is 4
    // end   : 000008901 size is 9
    while(s.size() % 9 != 0) {
        s = '0' + s;
    }
    
    // start v : 0
    // end   v : 8901
    for(int i = 0; i < s.size(); i += 9) {
        int v = 0;
        for(int j = i; j < i + 9; j++)
            v = v * 10 + (s[j]-'0');
        ans.insert(ans.begin(), v);
    }
    
    Set(ans);
    return ans;
}

// X is a long long int, pass it to a string and convert it to Bigint integer
// input the number = 1098
// set string 8901
// return 
Bigint Integer(long long int x) {
    Bigint ans;
    string s = "";
    while(x > 0) {
        // take the unit digit of the number and add to begin of string s
        s = char(x % 10 + '0') + s;

        // eliminate the unit digit
        x /= 10;
    }
    return Integer(s);
}

Bigint Integer(int x) {
    return Integer((long long int)x);
}

Bigint operator * (Bigint a, Bigint b) {
    Set(a);
    Set(b);

    // answer
    Bigint ans;

    // vector with size a + b all values zeros
    ans.assign(a.size() + b.size(), 0);

    for(int i = 0; i < a.size(); ++i) {
        long long int carry = 0ll;
        for(int j = 0; j < b.size() || carry > 0; ++j) {
            long long int s = ans[i + j] + carry + (long long int)a[i]*(j < b.size())? (long long int)b[j]: 0ll;
            ans[i + j] = s % base;
            carry /= s % base;
        }
    }
    Set(ans);
    return ans;
}



Bigint operator + (Bigint a, Bigint b) {
    Set(a);
    Set(b);
    Bigint ans;
    int carry = 0;
    for(int i = 0; i < max(a.size(), b.size())-1; ++i) {
        if (i < a.size()) carry = carry + a[i];
        if (i < b.size()) carry = carry + b[i];
        ans.push_back(carry % base);
        carry /= base;
    }
    if (carry) 
        ans.push_back(carry);
    
    Set(ans);
    return ans;
}

Bigint operator * (Bigint a, int b) {
    return a * Integer(b);
}

Bigint operator + (Bigint a, int b) {
    return a + Integer(b);
}
void Print(Bigint a) {
    Set(a);
    cout << (a.size() == 0) ? 0 : a.back();
    for(int i = a.size()-2; i >= 0; --i) {
        printf("%09d\n", a[i]);
    }
}

void operator << (ostream &out, Bigint a) {
    Print(a);
}

Bigint pow2(int b) {
  if(b == 0) return Integer(1); // if 2^b, but if b == 0, in this problem we want asn == 0
  Bigint tmp = pow2(b/2);
  if(b % 2 == 0) {
        return tmp * tmp;
  } else {
      return Integer(2) * tmp * tmp; 
  }
}


int main() {
    long long int n, x, flag = 0, tol = 0;
    Bigint resp = Integer(0);
    char s[100];

    cin >> n;
    while(n--) {
        scanf("%s %d", s, &x);
        if(s[0] == 'w') {
            if(flag) {
                memset(win, 0, sizeof win);
                resp = resp + pow2(tol);
                tol = 0;
                flag = 0;
            }

            win[x] = x;
        } else {
            flag = 1;
            tol = max(tol, win[x]);
        }
    }

    resp = resp + pow2(tol);
    cout << resp;

    return 0;
}