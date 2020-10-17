#include<bits/stdc++.h>

using namespace std;

int compare_two(const string a, const string b) {
    if(a == b) 
        return 1;
    else if(a.size() % 2 == 0 && b.size() % 2 == 0) {
        return 
        (compare_two(a.substr(0, a.size()/2), b.substr(0, b.size()/2)) && 
         compare_two(a.substr(a.size()/2, a.size()/2), b.substr(b.size()/2, b.size()/2)) ) || 
        (compare_two(a.substr(0, a.size()/2), b.substr(b.size()/2, b.size()/2)) && 
         compare_two(a.substr(a.size()/2, a.size()/2), b.substr(0, b.size()/2)) );
    } else return 0;
}

int equal(const string& a, const string& b, int a1, int a2, int b1, int b2) {
    int j = b1;
    for(int i = a1; i < a2 && j < b2; ++i) {
        if(a[i] == b[j]) {
            ++j;
        } else return 0;
    }
    return 1;
}

int compare(const string& a, const string& b, int a1, int a2, int b1, int b2) {
    if(equal(a, b, a1, a2, b1, b2))
        return 1;
    else if((a2 - a1) % 2 == 0 && (b2 - b1) % 2 == 0) {
        return 
        (compare(a, b, a1, a1+ ((a2-a1)/2), b1, b1 + ((b2-b1)/2)) && 
         compare(a, b, a1 + ((a2-a1)/2), a2, b1 + ((b2-b1)/2), b2) ) || 
        (compare(a, b, a1, a1 + ((a2-a1)/2), b1 + ((b2-b1)/2), b2) && 
         compare(a, b, a1 + ((a2-a1)/2), a2, b1, b1 + ((b2-b1)/2)) );
    } else return 0;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    // if(compare(a, b, 0, a.size(), 0, b.size()))
    //     cout << "YES" << endl;
    // else 
    //     cout << "NO" << endl;

    if(compare_two(a, b))
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;

    return 0;
}