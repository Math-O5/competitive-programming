 
//estrutura de dados
#include<iostream>
#include<set>
#include<map>

using namespace std;
int main() {
    set<int> cartas;
    set<int> ana;
    set<int> beatriz;

    int  a, b, aux;

    cin >> a >> b;
    for(int i = 0; i < a; ++i) {
        cin >> aux;
        ana.insert(aux);
    }
    for(int i = 0; i < b; ++i) {
        cin >> aux;
        beatriz.insert(aux);
    }

    a = ana.size();
    b = beatriz.size();

    ana.insert(beatriz.begin(), beatriz.end());

    cout << ana.size() - max(a, b) << '\n';
    return 0;
}
