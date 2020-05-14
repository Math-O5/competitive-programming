/* O trabalh do Papa */
/* https://www.ime.usp.br/~cef/XVmaratona/ */
/* dp - knapsack */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> caixas;
vector<int> dp[1002];
int n, a, b; // n : number packs, a and b auxiliars.

bool mySort(pair<int, int> a, pair<int, int> b) {
    return (a.second >= b.second)? true : false;
}

int recursao_dp(int index, int stand) {
    // the first row must be all zeros
    if(index == n)
        return 1;

    int pega, nao_pega;
    if(caixas[index].first > stand) {
        return dp[stand][index] = recursao_dp(index + 1, stand);
    }
    return dp[stand][index] = max(1 + recursao_dp(index + 1, min(stand - caixas[index].first, caixas[index].second)), recursao_dp(index + 1, stand));
   
}

int main() {

    cin >> n;
    for(int j = 0; j < n; ++j)
    for(int i = 0; i < 1000005; ++i)
    dp[j].push_back(0);

    int j = n, stand = 0;
    while(j--) {
        cin >> a >> b;
        if(b > a) {
            n--;
            continue;
        }
        stand = max(b, stand);
        caixas.push_back(make_pair(a, b - a));
    }

    sort(caixas.begin(), caixas.end(), mySort); // O (n long n )
    cout << recursao_dp(0, stand) << '\n';
    return 0;
}