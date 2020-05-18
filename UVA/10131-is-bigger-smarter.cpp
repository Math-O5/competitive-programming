// problem:
// https://s3-us-west-2.amazonaws.com/prod-runcodes-files/exercisefiles/14552/p10131.pdf?X-Amz-Content-Sha256=e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855&X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAI3OUHGVPPSQMGO5Q%2F20200517%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20200517T182414Z&X-Amz-SignedHeaders=Host&X-Amz-Expires=120&X-Amz-Signature=ec4ec7d41dde38e46f3cb6a81112e5a8fca7a722dbe9ba4602681a0bb5712fb8
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h> // memset
#include <algorithm> // lower_bound
#include <bitset>

using namespace std;

#define fs first
#define sd second
#define pb push_back
// #define mp make_pair
#define MAXN 600001

const int INF = 0x3f3f3f3f;
//priority_queue<pair<int, vector<pair<int, int>>>> elem;

struct Elephant{
    int id,
        w,
        s;
};

bool mySort(const Elephant& a, const Elephant& b){
    if (a.w != b.w)
        return a.w < b.w; 
    else return a.s > b.s;
}

int dp[MAXN]; // the lis until i
Elephant elem[MAXN];


int lis(int n) {

    dp[0] = 1;
    // simple lis
    for(int i = 1; i < n; ++i) {
        
        // the least peace is 1
        dp[i] = 1;
        
        for(int j = 0; j < i; j++) {
            if(elem[j].w < elem[i].w && elem[j].s > elem[i].s) dp[i] = max(dp[j] + 1, dp[i]);
        }

    }


    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = 0, a, b, i = 0;
    while(cin >> elem[n].w >> elem[n].s) {
        elem[n].id = n + 1; 
        ++n;
    }
    sort(elem, elem + n, mySort);
    lis(n);

    return 0;
}