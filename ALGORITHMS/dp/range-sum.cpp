/*
    Given an array of n integers (different from zero)
    Fin de maximum range sum 
    A = {4, -2, 40}
    The max range sum of A is (0, n-1) itself. 
*/
#include <iostream>
#include <vector>

using namespace std;

// If all numbers if non-negative, the max range sum is sum of all elements of A.
// If there's a negative, it can be in range if the adjancents values ...positive + negative > 0
int main() {
    int a, b, s;
    
    // the number case tests
    cin >> b;

    for(int j = 1; j <= b; ++j) {
       
        // the num of elements
        cin >> s;
        int ans = 0, sum = 0;

        for(int i = 1; i <= s; ++i) {
            cin >> a;
            sum += a;
            
            ans = max(ans, sum);    // storage the maximum sum
            sum = max(0, sum);   // if sum decrease, then it's no belong more to maximum range sum
        }
        cout << ans << endl;
    }
    return 0;
}
