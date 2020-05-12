/* O trabalh do Papa */
/* https://www.ime.usp.br/~cef/XVmaratona/ */
/* dp - knapsack */
#include <iostream>
#include <vector>
#include <algorithm>
#include<bitset>

using namespace std;

vector<pair<int, int>> caixas;

int knapsack(bitset<1010> bs, int peso, int index) {
    int ans = 0 ;
    for(int i = 0; i < (int)caixas.size(); ++i) {
        if(bs[i] == 1) {
            bs[i] = 0;
            if(peso <= caixas[i].second)  {
                ans = max(ans, (1 + knapsack(bs, peso + caixas[i].first, (index + 1) % (int)caixas.size()));
            }
            bs[i] = 1;
        }
    }

    return ans;
}

int main() {
    bitset<1010> index;
    int n, a, b; // n : number packs, a and b auxiliars.

    cin >> n;
    while(n--) {
        cin >> a >> b;
        caixas.push_back(make_pair(a, b - a));
    }

    index.set();
    //sort(caixas.begin(), caixas.end(), mySort); // O (n long n )
    cout << knapsack(index, 100000, 0) << '\n';
    return 0;
}