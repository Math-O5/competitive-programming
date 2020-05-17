// LIS - Longest Increase Sequence
// https://en.wikipedia.org/wiki/Patience_sorting
// https://neps.academy/lesson/163
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h> // memset
#include <algorithm> // lower_bound

using namespace std;

#define fs first
#define sd second
#define pb push_back
#define MAX 300000

const int INF = 0x3f3f3f3f;

int n, aux;
vector<int> topo;
vector<int> numbers;

// distribution of numbers in stacks such that: Put the number in the leftmost stack that the number is greater o euqla
// that the number. If there1s not, create a stack in the rightmost side.
// The number os stack is the length of LIS.

// Input:
// 8
// -7 10 9 2 3 8 8 1
// 6
// 3 4 3 5 2 7

// stack one:   -7
// stack two:    1 2 9 10
// stack three:  3
// stack four:   8 8
// O (nlogn) time
void lis() {
    topo.pb(numbers[0]);
    vector<int>::iterator it;

    for(int i = 1; i < n; ++i) {
        it = lower_bound(topo.begin(), topo.end(), numbers[i]);
        if(it == topo.end())
            topo.pb(numbers[i]);
        else
            *it = numbers[i];        
    }

    cout << topo.size();
}

// Find the numbers of LIS
// We create a new stack always that the number is greater than the top of the last stack.
// So, the top past is part of the LIS.
vector<int> findLIS() {
    topo.pb(numbers[0]);
    vector<int>::iterator it;
    vector<int> seq, ultimaPilha;

    for(int i = 1; i < n; ++i) {
        it = lower_bound(topo.begin(), topo.end(), numbers[i]);
        if(it == topo.end()) {
            seq.pb(topo.back());
            ultimaPilha.clear();
            ultimaPilha.pb(numbers[i]);
            topo.pb(numbers[i]);
        }
        else {
            *it = numbers[i];        
            ultimaPilha.pb(numbers[i]);
        }
    }

    reverse(ultimaPilha.begin(), ultimaPilha.end());

    while(ultimaPilha.size()) {
        if(seq.back() < ultimaPilha.back()) {
            seq.pb(ultimaPilha.back());
            ultimaPilha.pop_back();
        } else break;
    }

    return seq;
}

// Union-Find implementation
// https://neps.academy/lesson/163
vector<int> unionLIS() {
    topo.pb(numbers[0]);
    vector<int>::iterator it;
    vector<int> seq, resp;
    int pos[MAX], pai[MAX]; // the real pos in array and father

    for(int i = 0; i < n; ++i) {
        it = lower_bound(topo.begin(), topo.end(), numbers[i]);
        
        int p = it - topo.begin();
        if(it == topo.end()) {
            topo.pb(numbers[i]);
        }
        else {
            *it = numbers[i];        
        }

        pos[p] = i;
        if(p == 0) 
            pai[i] = -1;
        else
            pai[i] = pos[p-1];

    }

    int i = pos[topo.size()-1];


    while(i >= 0) {
        resp.pb(numbers[i]);
        i = pai[i];
    }

    reverse(resp.begin(), resp.end());
    return resp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n;
    
    for(int i = 0; i < n; ++i) {
        cin >> aux;
        numbers.pb(aux);
    }   

    vector<int> ans = unionLIS();

    for(auto i : ans) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}