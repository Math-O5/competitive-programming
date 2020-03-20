#include<bits/stdc++.h>
#include<iostream>
#include<vector>
std::vector<int>push_back();
#define N 100000
using namespace std;

int igual_1(int n, int i) { //3 //2 //1
     if (n==1) return i--;
     if(n%2==0) {
        n = n/(2);
        i++;
        igual_1(n,i);
     }
     else {
        n = (3*n)+1;
        i++;
        igual_1(n,i);
     }

}

int main() {
    int n;
    cin>> n;
    int i=0;
    cout << igual_1(n, i);

return 0;
}
