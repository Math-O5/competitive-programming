 #include<iostream>

using namespace std;

int main() {
    int n, sum = 0, a, b, c, d;
	cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a >> b >> c >> d;
        sum += (a-c)*(a-c) + (b-d)*(b-d);      
    }
    cout << sum << '\n';
    return 0;
}
