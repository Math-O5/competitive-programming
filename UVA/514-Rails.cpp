// UVA 540 rails
#include<iostream>
#include<stack>

using namespace std;
 
int n, m, aux;
bool flag = false;

int main() {
    while(cin >> n, n > 0) {
        int line = true;
        while(line) {
            stack<int> s;
            flag = true;
            int  j = 1;
            for(int l = 1; l <= n; ++l) {
                // cout << j << endl;
                cin >> aux;

                if(j == 1 && aux == 0) {
                    flag = false;
                    line = false;
                    cout << endl;
                    break;
                }

                if(aux < j && s.size() && s.top() == aux) {
                    // cout << "Eu sou 2: " << s.top() << ' ' << aux << endl; 
                    s.pop();
                    continue;
                } else if(aux < j) {
                    // cout << "aux: " << aux << " j: "<< j << endl;
                    ++j;
                    flag = false;
                    continue;
                } else if (aux > j) {
                    // the train must be greater order, store the shrinker position
                    while(aux > j) {
                        s.push(j);
                        ++j;
                    } 
                    ++j;
                    // cout << "Saio com 4: " << j << endl;
                } else {
                    ++j;
                }

            }

            if(flag && line)
                cout << "Yes\n";
            else if(line) 
                cout << "No\n";

            while(s.size()) {
                s.pop();
            }

        }
    }
    cout << endl;
    return 0;
}