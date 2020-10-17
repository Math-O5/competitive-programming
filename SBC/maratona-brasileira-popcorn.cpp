#include<bits/stdc++.h>

using namespace std;

int n, c, t, aux, maxn;
vector<int> popcorn;

bool match(int range) {
    int part = 1, sum = 0;
    for(int i = 0; i < n; ++i) {
        // one people can hadle
        if(ceil((sum + popcorn[i])/(double)t) <= range) {
        //    cout << ceil((sum + popcorn[i])/(double)t) << "  " << ceil((sum + popcorn[i])/(double)t) << endl;
           sum += popcorn[i];
           // need more people
        } else {
            part++; --i;
            sum = 0;
        }
        
        if(part > c) return false;
    }

    return true;
}

int bisection() {

    int minn = 1;
    // maxn = 1e9;
    while(minn < maxn) {
        int mid = (minn + maxn) >> 1;
        if(match(mid)) {
            maxn = mid;
        }
        else minn = mid + 1;
    }

    return minn;
}

int main() {

    cin >> n >> c >> t;

    for(int i = 0; i < n; ++i) {
        cin >> aux;
        popcorn.push_back(aux);
        maxn += aux;
    }
    
    cout << bisection() << endl;
    return 0;
}