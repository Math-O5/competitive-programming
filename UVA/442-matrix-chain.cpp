#include<bits/stdc++.h>

using namespace std;

int dim[26][2];

int main() {
    int n,a,b;
    char c;
    string s;
    vector<int> exp;

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> c;
        
        int index = (int)(c-'A');
        
        cin >> dim[index][0] >> dim[index][1];
    }
    int error, result;
    while(getline(cin, s)) {
        error = 0;
        result = 0;
        exp.clear();
        if(s=="")
            continue;
        for(int i = 0; i < (int)s.size(); ++i) {
            if(s[i] == '(')
                continue;
            else if(s[i] == ')') {
                int n = (int)exp.size();
                int a = exp[n-1], b = exp[n-2], c = exp[n-3], d = exp[n-4];
                if(b != c) {
                    error = 1;
                    cout << "error\n";
                    break;
                }    
                result += (a * b * d);   
                exp.pop_back();
                exp.pop_back();
                exp.pop_back();
                exp.push_back(a);
            } else {
                exp.push_back(dim[(int)(s[i]-'A')][0]);
                exp.push_back(dim[(int)(s[i]-'A')][1]);
            }
        }
        if(!error) 
            cout << result << endl;
    }

    return 0;   
}