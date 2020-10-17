#include<iostream>
#include<string>

using namespace std;

int count(const string& str, int ini, int fim, char nivel) {
    int count = 0;

    for(int i = ini; i <= fim; ++i){
        if(str[i] == nivel)
            ++count;
    }
    return count;
}

int magic(const string& str, int ini, int fim, char nivel)
{
    if(ini == fim) {
        return (str[ini] != nivel);
    }

    int mid = ini + (fim - ini)/2;
    int k = (fim - ini+1)/2;
    return min((k- count(str, ini, mid, nivel)) + magic(str, mid+1, fim, nivel+1),
                (k-count(str, mid+1, fim, nivel)) + magic(str, ini, mid, nivel+1));
    
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin >> n;

        cin >> s;
        cout << magic(s, 0, n-1, 'a') << endl;
    }

    return 0;
}