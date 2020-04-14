 
#include <iostream>

using namespace std;

typedef long long int ll;

/*
    Check if how much number in [1,n] are divisibily by all number inrange [2,10].
    n can grow up n^18
    time 0.5
*/
// 2*3*4*5*6*7*8*9*10 = 2 2 2 3 3 5 7  = 5*7*8*9 = 2520
int main()
{   
    ll k = 2520, n;
    cin >> n;
    cout << n/k << endl;
    return 0;
}
