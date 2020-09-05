#include<iostream>
#include<stack>

using namespace std;

int main() {
    int n, line, m, flag;
    string trash;

    while(cin >> n, n > 0) {
        
        line = true;
        while(line) {

            stack<int> s;
            flag = true;
            for(int i = 1; i <= n;) {
                cin >> m;

                if(!m) {
                    line = false;
                    break;
                }

                if(m < i) {
                    if(!s.size() || s.top() != m) {
                        cout << "Aqui " << s.top() << endl;
                        cout << "Aqui " << m << endl;
                        flag = false;
                        getline(cin, trash);
                        break;
                    } else {
                        s.pop();
                        ++i;
                    } 
                } else if(m > i) {
                    while(m > i) {
                        s.push(i);
                        ++i;
                    }
                } else {
                    ++i;
                }

            }
            if(flag && line)
                cout << "Yes\n";
            else if(line) 
                cout << "No\n";
        }

        
    }

}