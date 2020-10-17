#include <bits/stdc++.h>

using namespace std;

#define fs first
#define sd second
#define pb push_back
#define vii vector<int>
#define pii pair<int, int>
#define MAXN 120000

const int INF = 0x3f3f3f3f;

int n, aux, a, b;
double tempo;

struct Pos {
    double t; 
    int x, y;
    Pos(double t, int x, int y) : t(t), x(x), y(y) {}
};

// vector<Pos> cas;
queue<Pos> cas; 

double dis(int x, int y, int x1, int y1) {
    return sqrt( ((x1 - x)*(x1 - x)) + ((y1 - y)*(y1 - y)) );
}

double solve(int nv, int x, int y, double tmp, queue<Pos> bb) {
    if(nv >= n) {
        return 0;
    } 

    double ans = INF;
    for(int i = 0; i < bb.size(); ++i) {
        Pos p = bb.front();
        bb.pop();
        double time = dis(x, y, p.x, p.y);
        double cost = 0.0;

        // cost
        if(time + tmp > p.t) {
            cost = time + tmp - p.t;
        } 

        ans = min(ans, cost + solve(nv + 1, p.x, p.y, tmp + time, bb));

        bb.push(p);
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> tempo >> a >> b;
        Pos pos(tempo, a, b);
        cas.push(pos);
    }

    cout << fixed;
    cout << setprecision(3) << solve(0, 0, 0, 0.0, cas) << endl;

    return 0;
}