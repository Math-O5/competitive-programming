#include<bits/stdc++.h>

using namespace std;

int n, k;
priority_queue<int> both, trashjoao, trashmaria;
vector<int> joao, maria;
int solve() {
    int t, a, b;
    cin >> n >> k;

    for(int i = 0; i < n; ++i) {
        cin >> t >> a >> b;
        if(a == 0 && b == 0) continue;

        // need complete scheduçe
        if(k) {
            if(a == 1 && b == 1) {
                both.push(t);
                --k;
            } else if(a == 1) {
                trashmaria.push(-t);
            } else {
                trashjoao.push(-t);
            }
        } 
        // find optimal
        else {
            if(a == 1 && b == 1) {
                if(both.top() > t) {
                    both.pop();
                    both.push(t);
                }
            } else if(a == 1) {
                trashmaria.push(-t);
            } else {
                trashjoao.push(-t);
            }
        }
    }

    while(k && trashjoao.size() && trashmaria.size()) {
        maria.push_back(-trashmaria.top());
        joao.push_back(-trashjoao.top());
        trashjoao.pop();
        trashmaria.pop();
        --k;
    }

    while(trashjoao.size() && trashmaria.size() && both.size() ) {
        int topM = -trashmaria.top();
        int topJ = -trashjoao.top();
        if(both.top() > topM + topJ) {
            both.pop();
            maria.push_back(topM);
            joao.push_back(topJ);
            trashjoao.pop();
            trashmaria.pop();
        } else break;
    }

    if(k) return -1;
    else {
        int sum = 0;
        for(int i = 0; i < maria.size(); ++i) {
            // cout << ' ' << maria[i] << ' ';
            sum += maria[i]; 
        }
        for(int i = 0; i < joao.size(); ++i) {
             sum += joao[i]; 
            // cout << ' ' << joao[i] << ' ';
        }   
        while(both.size()) {
            // cout << both.top() << endl;
            sum += both.top();
            both.pop();
        }
        return sum;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << solve() << endl;
    return 0;
}