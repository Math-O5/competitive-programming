#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> s;

bool comp(char a, char b) {
	if( (a == '(' && b == ')') ||
       	(a == '[' && b == ']') ||
       	(a == '{' && b == '}')) {
    	return true;
    }
    return false;
}

int main() {
	int n;
    char c;
    string str;
    
    cin >> n;
    
    while(n--) {
    	cin >> str;
        s.clear();
        for(auto i: str) {
            if(!s.empty() || !comp(s.top(), i) ) {
            	s.push(i);
            } else {
            	s.pop();
            }
        }
        
        if(!srt.size()) {
        	cout << "S\n";
        } else {
            cout << "N\n";
        }
    }
	return 0;
}