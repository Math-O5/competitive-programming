#include<bits/stdc++.h>

using namespace std;

map<int, int> numbers;
int num[1500];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n, aux;
    cin >> n;
    for(int i = 0; i < n*n; ++i) {
        cin >> aux;
        numbers[aux] += 1;
    }

    // auto x = max_element(numbers.begin(), numbers.end(),
    // [](const pair<int, int>& p1, const pair<int, int>& p2) {
    //     return p1.second < p2.second; });

    // num[0] = x->second;
    // numbers[x->first] = 0;

    // auto y = max_element(numbers.begin(), numbers.end(),
    // [](const pair<int, int>& p1, const pair<int, int>& p2) {
    //     return p1.second < p2.second; });

    // // cout << y->second << endl;
    // num[1] = y->second;
    // numbers[y->first] = 0;


    // for(int i = 1; i < n; ++i) {
    //      auto z = max_element(numbers.begin(), numbers.end(),
    // [](const pair<int, int>& p1, const pair<int, int>& p2) {
    //     return p1.second < p2.second; });

    //     num[i] = z->second;
    //     // numbers[z->first] = 0;
    //     numbers.erase(z);
    //     for(int j = 0; j < i; ++j) {
    //         int g = gcd(num[i], num[j]);
    //         int h = g;
    //         // cout << g << endl;
    //         // numbers[numbers.find(g)->first]=0;
    //         cout << numbers.find(g)->second << ' ';
    //         numbers.erase(g);
    //         cout << numbers.find()->second << ' ';
    //         numbers.erase(g);
    //         cout << endl;
    //         // numbers[numbers.find(g)->first]=0;

    //     }
    int i = 0;
    for(auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
        int tmp = it->first;
        while(it->second) {
            num[i] = tmp;
            it->second--;
            int j = 0;
            while(j < i) {
                int g = gcd(num[i], num[j]);
                numbers[g] -= 2;
                ++j;
            }
          ++i;
        }
    }

    for(int i = 0; i < n; ++i)
        cout << num[i] << ' ';
    cout << endl;
    return 0;
}