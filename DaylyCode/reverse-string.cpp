/*
    Daily Byte 1

    “Cat”, return “taC”
    “The Daily Byte”, return "etyB yliaD ehT”
    “civic”, return “civic”
*/
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h> // memset
#include <algorithm> // lower_bound
#include <iomanip>
#include <bitset>
    // #include <bits/stdc++.h>

using namespace std;

#define fs first
#define sd second
#define pb push_back
#define vii vector<int>
#define pii pair<int, int>
#define MAXN 120000

const int INF = 0x3f3f3f3f;

// Function to reverse a string
void reversed(string& str)
{
    int n = str.length();
 
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

string recursive_reverse(string str) {
    if (str.length() == 1)
        return str;
    return recursive_reverse(str.substr(1)) + str[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    reversed(s);
    cout << s << endl;
    cout << recursive_reverse(s) << endl;
    return 0;
}