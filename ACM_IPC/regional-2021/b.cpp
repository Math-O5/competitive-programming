#include <bits/stdc++.h>

using namespace std;

struct LenghtSort
{
    bool operator () (const string &a, const string &b)
    {
        return (a.size() < b.size()) ;
    }
};

int n, m;

int checkScore(int beg, vector<char> a, string sub){
    for(int i = 0; i < (int)sub.size(); i++){
        if(sub[i] != a[beg]) return 0;
        beg = (beg+1)%n;
    }
    return (int)sub.size();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string sub;
    set<string, LenghtSort> substrings;
    set<string, LenghtSort> ::iterator it;
    int score = 0;

    cin >> n >> m;
    vector<char> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < m; i++){
        cin >> sub;
        if((int)sub.size() < n)
            substrings.insert(sub);
    }

    if(!substrings.empty()) {
        for(it = substrings.begin(); it != substrings.end(); it++){
            for(int i = 0; i < n; i++){
                if((*it)[0] == a[i]){
                    score = checkScore(i, a, (*it));
                    if(score) break;
                }
            }
            if(score) break;
        }
    }

    cout << score << '\n';

    return 0;
}