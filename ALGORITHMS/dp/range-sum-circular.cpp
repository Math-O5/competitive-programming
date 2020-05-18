/*
    Given an array of n integers (different from zero)
    Fin de maximum range sum 
    A = {4, -2, 40}
    The max range sum of A is (0, n-1) itself. 
*/
// https://www.youtube.com/watch?v=os4B7MlHAbs
#include <iostream>
#include <vector>

using namespace std;

int kadane(vector<int> elems,int n) {
   int ans = 0, sum = 0;
   for(int i = 1; i <= n; ++i) {
            sum += elems[i];     
            ans = max(ans, sum);  // storage the maximum sum
            sum = max(sum, 0);
    }
    return ans;
}

int maximumCircleArraySum(vector<int> elems, int n) {
    int total = 0, k = 0;

    k = kadane(elems, n);
    for(int i = 1; i <= n; ++i) {   
        total += elems[i];
        elems[i] = -elems[i];
    }

    int min_range = kadane(elems, n);
    int max_circle_range = total + min_range; // 
    
    return (max_circle_range > k)? max_circle_range : k;     
}

// If all numbers if non-negative, the max range sum is sum of all elements of A.
// If there's a negative, it can be in range if the adjancents values ...positive + negative > 0
int main() {
    int a, b, n;

    // the size array
    cin >> n;
    vector<int> elems(n+2);

    for(int j = 1; j <= n; ++j) {
        cin >> elems[j];
    }

    cout << maximumCircleArraySum(elems, n) << endl;
    return 0;
}
