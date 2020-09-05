#include<iostream>
#include<map>
#include<iomanip>
#include<string>

using namespace std;

int n, k, m, value;
double acumulate;
char key;
string article;

int main() {
    map<char, int> pay;
    cin >> n;
    while(n--) {
        cin >> k;
        for(int i = 0; i < k; ++i) {
            cin >> key >> value;
            pay[key] = value;
        }
        cin >> m;

        acumulate = 0;
        for(int i = 0; i <= m; ++i) {
            getline(cin, article);
            for(int j = 0; j < article.size(); ++j) {
                acumulate += pay[article[j]];
            }
        }

        acumulate /= 100.0;
        cout << setprecision(2) << fixed << (double)acumulate;
        cout << "$\n";

        pay.clear();
    }
    return 0;
}