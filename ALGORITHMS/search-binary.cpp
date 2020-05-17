// Complexity O((log N) + 1)
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> elements;

const double eps = 1e-8;

double f(double x) {
    // function f(x)
}

// Slowly approximation f soluion
double bissection(double low, double high) {
    double center;
    while(high - low > eps) {
        center = (high - low)/2;
        // f(low) and f(high) must be of different signals
        if(f(low) * f(high) <= 0) {
            high = center; // decrease
        } else {
            low = center; // increase
        }
    }
    return (low+high)/2;
}

int binary_search(int value) {
    int ini = 0, fim = (int)elements.size();

    while(ini <= fim) {
        int mid = (ini + fim) / 2;

        if(elements[mid] == value) {
            return mid;
        } else if(elements[mid] > value) {
            fim = mid - 1;
        } else {
            ini = mid + 1;
        }
    }
    return -1; //not found
}

int main() {
    elements.push_back(3);
    elements.push_back(3);
    elements.push_back(1);
    elements.push_back(2);
    elements.push_back(4);
    elements.push_back(7);
    elements.push_back(4);
    elements.push_back(3);
    elements.push_back(3);
    sort(elements.begin(), elements.end());

    cout << "Is 4 in position: " << binary_search(4) << endl;

    vector<int>::iterator low, up;
    low = lower_bound(elements.begin(), elements.end(), 4);
    up = upper_bound(elements.begin(), elements.end(), 4);

    cout << "for 4, low is: " << *low << " and up is: " << *up << endl;

    cout << "serching element 4: " << binary_search(elements.begin(), elements.end(), 4) << endl; 
    return 0;
}