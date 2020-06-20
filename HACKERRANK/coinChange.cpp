//problem:
// https://s3-us-west-2.amazonaws.com/prod-runcodes-files/exercisefiles/11812/1.pdf?X-Amz-Content-Sha256=e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855&X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAI3OUHGVPPSQMGO5Q%2F20200620%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20200620T182817Z&X-Amz-SignedHeaders=Host&X-Amz-Expires=120&X-Amz-Signature=504f322d0378238c0a2b59c79404c5632fd3bc21afc692280567f026855c7213
#include <iostream>
using namespace std;

int n, m, arr[100000], dp[1000][1000];

int coin (int value, int i) {
    if(value == m)
        return 1;
    if(i == n || value > m)
        return 0;

    if(dp[value][i] != 0)
       return dp[value][i];

    return dp[value][i] = coin(value + arr[i], i) + coin(value, i + 1);
}

int main() {
    cin >> m >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << coin(0, 0);
    return 0;
}