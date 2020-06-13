#include<bits/stdc++.h>
#include<iostream>
#include<vector>
std::vector<int>push_back();
#define N 100000
using namespace std;


int fibonacci(int n) { //3 //2 //1
    int fib[n];
    if(n==0) return fib[0] = 1;
    if(n==1) return fib[1] = 1;

    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int n;
    cin>> n;
    cout << fibonacci(n);

return 0;
}
