// 507 Jill Rides Again - (DP - Sum Range) 
// https://onlinejudge.org/external/5/507.pdf
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b, s;

    cin >> b;

    for(int j = 1; j <= b; ++j) {
        cin >> s;
        int ans = 0, sum = 0, ini = 1, fim = 1, newi = 1;
        
        for(int i = 1; i < s; ++i) {
            cin >> a;
            sum += a;
            if(sum > ans) {
                ini = newi;
                ans = sum;
                fim = i + 1;
            } 

            if(sum == ans && fim - ini <= i + 1 - newi) {
                ini = newi;
                ans = sum;
                fim = i + 1;
            }
             
            if(sum < 0) {
                newi = i + 1;
                sum = 0;
            } 
           
            
        }

    if(ans > 0)
        cout << "The nicest part of route " << j << " is between stops " << ini << " and " << fim << '\n';
    else {
        cout << "Route " << j << " has no nice parts\n";
    }
    }
    return 0;
}