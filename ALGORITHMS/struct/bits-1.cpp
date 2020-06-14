#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h> // memset
#include <algorithm> // lower_bound
#include <iomanip>
#include <bitset>

using namespace std;

#define fs first
#define sd second
#define pb push_back
#define vii vector<int>
#define pii pair<int, int>
#define MAXN 120000

const int INF = 0x3f3f3f3f;

bitset<100> bs;

bool isTurnOn(int numero, int pos) {
    return (numero & (1 << pos));
}

int leastSignificantBit(int numero) {
    return numero & (~numero + 1);
}

int countBits(int numero) {
    int sets = 0;
    while(numero > 0) {
        sets++;
        numero -= leastSignificantBit(numero);
    }
    return sets;
}

/**
 * IS pwer of 2
 * 
 * num = 4 = (100)
 * num - 1 = 3  (11)
 * 
 * 3 & 4 => (11) & (100) = 0
 */ 
bool isPowerOfTwo(int numero) {
    if(!numero) return false;
    return ((numero & (numero - 1)) == 0)? true : false;
}

void turnOnBit(int* numero, int i) {
    *numero |= (1 << i);
}

/**
 * Turn off the bit
 */
void turnOffBit1(int* numero, int i) {
    *numero &= (1 << i);
    *numero ^= (1 << i); 
}

void turnOffBit2(int* numero, int i) {
    if(isTurnOn(*numero, i)) {
        *numero -= (1 << i);
    } 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    return 0;
}