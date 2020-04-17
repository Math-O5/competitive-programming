/* Manhatta x0 y0 x1 y1 */
#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int sum = 0, a, b, c, d;
    cin >> a >> b >> c >> d;
    sum = abs(a-c) + abs(b-d);      
    cout << sum << '\n';
    return 0;
}