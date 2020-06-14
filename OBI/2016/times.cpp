#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h> // memset
#include <algorithm> // lower_bound
#include <iomanip>
    // #include <bits/stdc++.h>

using namespace std;

#define fs first
#define sd second
#define pb push_back
#define vii vector<int>
#define pii pair<int, int>
#define MAXN 120000

vector<pair<int, string>> alunos;

bool comp(const pair<int, string>& a, const pair<int, string>& b) {
    return (a.fs > b.fs);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, t, h;
    string s;

    cin >> n >> t;
    for(int i = 0; i < n; ++i) {
        cin >> s >> h;
        alunos.pb(make_pair(h, s));
    }

    sort(alunos.begin(), alunos.end(), comp);

    for(int i = 0; i < t; ++i) {
        vector<string> v;
        for(int j = i; j < n; j += t) {
            v.pb(alunos[j].sd);
        }

        sort(v.begin(), v.end());
        cout << "Time " << i + 1 << endl;
        for(auto name : v) {
            cout << name << endl;
        }
        cout << endl;
    }

    return 0;
}