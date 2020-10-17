#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, a ,b;
    cin >> n >> a >> b;

    int midA = n/2;
    int midB = (n - midA);
    
    // the least piece
    int left = a/midA;
    int right = b/midB;
    int least = min(right, left);

    // to left
    int tmpA = midA;
    int tmpB = midB;
    while(tmpA - 1 > 0) {
        tmpA--;
        tmpB++;

        int tmp_l = a/tmpA;
        int tmp_r = b/tmpB;

        int tmp_least = min(tmp_l, tmp_r);

        if(tmp_least >= least) {
            least = tmp_least;
        } else break;
    }

    // to right
    tmpA = midA;
    tmpB = midB;
    while(tmpB -  1 > 0) {
        tmpA++;
        tmpB--;

        int tmp_l = a/tmpA;
        int tmp_r = b/tmpB;

        int tmp_least = min(tmp_l, tmp_r);

        if(tmp_least >= least) {
            least = tmp_least;
        } else break;
    }

    cout << least << endl;
    return 0;
}