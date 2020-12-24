#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h> // memset
#include <algorithm> // lower_bound
#include <iomanip>
#include <bitset>
#include<math.h>
    // #include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define vii vector<int>
#define pii pair<int, int>
#define MAXN 160

const int INF = 0x3f3f3f3f;
int num_test, n, grafo[MAXN][MAXN], grafoB[MAXN][MAXN], s, t, c, a, b, cost;
double d;
int total_peguens;
vector<pair<double, double>> pos; // x, y
vector<pair<double, double>> floe; // number of penguins and maximum number of jump off

bool bfs(int parent[]) 
{ 
    bool visited[n+5]; 
    memset(visited, 0, sizeof(visited)); 
  
    queue <int> q; 
    q.push(s); 
    visited[s] = true; 
    parent[s] = -1; 
    while (!q.empty()) 
    { 
        int u = q.front(); 
        q.pop(); 
  
        for (int i = 1; i <= n; i++) 
        { 
            if (visited[i]==false && grafo[u][i] > 0) 
            { 
                q.push(i); 
                parent[i] = u; 
                visited[i] = true; 
            } 
        } 
    } 
    return (visited[t] == true); 
} 

int flow() {
    int lim = floe[s].first;
    int parent[n+5], maxF=0;
    while(lim && bfs(parent)) {
        int minF = INF;
        int u;
        for(int i = t; i != s; i = parent[i]) {
            u = parent[i];
            minF = min(minF, grafo[u][i]);
        }

        if(minF >= lim) {
            minF = lim;
            lim = 0;
        } else {
            lim -= minF;
        }
        for(int i = t; i != s; i = parent[i]) {
            u = parent[i];
           grafo[u][i] -= minF;
        //    grafo[i][u] += minF;
        }
        maxF += minF;
    }
    // cout << "maxF" << maxF << ' ' << floe[s].first << endl;
    return maxF;
}

int max_flow() {
    int maxf = 0;
    for(int i = 0; i < n; ++i) {
        if(i != t) {
            s = i;
            int p = flow();
            cout << "flow: p >" << p << endl;
            if(p == floe[i].first)
                maxf += p;
        
            else break;
        }
    }
    return maxf;
}

double euclidian(const pair<double, double>& posA,const pair<double, double>& posB) {
    return ((posA.x - posB.x)*(posA.x - posB.x)) +
                         ((posA.y - posB.y)*(posA.y - posB.y));
}

void contruct_graph() {
    d *= d;
    for(int i = 0; i < (int)pos.size()-1; ++i) {
        for(int j = i + 1; j < (int)pos.size(); ++j) {
            if(euclidian(pos[i], pos[j]) <= d) {
                grafoB[i][j] += floe[i].second;
                grafoB[j][i] += floe[j].second;
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    double x, y;
    int damage, n_penguens;
    cin >> num_test;
    for(int g = 0; g < num_test; ++g) {
        total_peguens = 0;
        pos.clear();
        floe.clear();
        memset(grafoB, 0, sizeof(grafoB));
        cin >> n >> d;
        for(int j = 0; j < n; ++j) {
            cin >> x >> y >> n_penguens >> damage;
            total_peguens += n_penguens;
            pos.pb(make_pair(x, y));
            floe.pb(make_pair(n_penguens, damage));
        }
        contruct_graph();
        int flag = 0;
        for(int i = 0; i < n; ++i) {
            t = i; // end
            for(int l = 0; l < n; ++l) {
                for(int k = 0; k < n; ++k) {
                    grafo[l][k] = grafoB[l][k];
                }
            }
            int p = max_flow() + floe[t].first;
            // cout << p << " == " << floe[t].first << endl;
            if(p == total_peguens) {
                flag = 1;
                cout << i << ' ';
            }
            // cout << "p> " << p << " = " << total_peguens << endl;
        }
        if(flag) 
            cout << '\n';
        else {
            cout << "-1\n";
        }
    }
    return 0;
}