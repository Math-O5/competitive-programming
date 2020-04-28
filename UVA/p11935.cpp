#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<string.h>
#include<iomanip>
using namespace std;

int now;
double max_tank[2], n, past, d, leaks;
char read[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> d) {
        cin >> read;
        if(!strncmp(read, "Go", 2)) {
            max_tank[now] += (double)( (n+leaks) * (d - past) ) / (double)100.0;
            past = 0;
            cout << setprecision(3) << fixed << max(max_tank[0], max_tank[1]) << '\n';
            max_tank[0] = max_tank[1] = 0;
            leaks = 0;
        } else if(!strncmp(read, "Fu", 2)) {
            max_tank[now] += (double)( (n+leaks) * (d - past) ) / (double)100.0;
            past = d;
            cin >> read;
            cin >> n;
            if(n == 0) break;
        } else if(!strncmp(read, "Ga", 2)) {
            cin >> read;
            max_tank[now] += (double)( (n+leaks) * (d - past) ) / (double)100.0;
            past = d;
            if(max_tank[0] <= max_tank[1]) {
                now = 0;
                max_tank[0] = (double)0.0;
            } else {
                now = 1;
                max_tank[1] = (double)0.0;
            }
        } else if(!strncmp(read, "Me", 2)) {
            max_tank[now] += (double)( (n+leaks) * (d - past) ) / (double)100.0;
            past = d;
            leaks = 0;
        } else if(!strncmp(read, "Le", 2)) {
            max_tank[now] += (double)( (n+leaks) * (d - past) ) / (double)100.0;
            past = d;
            leaks += (double)100.0;
        }   
    }

    return 0;
}