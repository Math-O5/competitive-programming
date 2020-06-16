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

        // while is not empty
        while(!s.empty())
            s.pop();

        for(auto i: str) {

            // while is empty or the character did not match
            if(s.empty() || !comp(s.top(), i) ) {
            	s.push(i);
            } else {
            	s.pop();
            }
        }
        
        if(!s.size()) {
        	cout << "S\n";
        } else {
            cout << "N\n";
        }
    }
	return 0;
}