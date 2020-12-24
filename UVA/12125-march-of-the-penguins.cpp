#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <string.h> // memset
#include <algorithm> // lower_bound
#include<math.h>
    // #include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define vii vector<int>
#define pii pair<int, int>
#define MAXN 200

const int INF = 0x3f3f3f3f;
int num_test, n, grafo[MAXN][MAXN], grafoB[MAXN][MAXN], s, t;
double d;
int total_peguens;
vector<pair<double, double>> pos; // x, y
vector<pair<double, double>> floe; // number of penguins and maximum number of jump off
int dam[MAXN];

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
        if(dam[u] <= 0)
            break;
        for (int i = 0; i < n; i++) 
        { 
            if (visited[i]==false && (grafo[u][i] > 0 || grafo[i][u] > 0)) 
            { 
                q.push(i); 
                parent[i] = u; 
                visited[i] = true; 
                if(visited[t] == true)
                    return true;
            } 
        } 
    } 
    return (visited[t] == true); 
} 

int flow() {
    int lim = floe[s].first;
    int parent[n+5], maxF=0;
    int u;  
    while(lim && bfs(parent)) {
        // cout << "lim" << lim << endl;
        int minF = INF;
        for(int i = t; i != s; i = parent[i]) {
            // cout << i << ' ';
            u = parent[i];
            // int tmp = max(dam[i]);
            minF = min(minF, dam[u]);
        }
        // cout << endl;
        // cout << "min " << minF << " lim "<< lim << endl;

        if(minF >= lim) {
            minF = lim;
            lim = 0;
            // maxF + lim;
        } else {
            lim -= minF;
        }
        if(!minF)
            return -1;
        
        for(int i = t; i != s; i = parent[i]) {
                u = parent[i];
            // grafo[u][i] -= minF;
            // grafo[i][u] -= minF;
            // if(grafo[i][u] < 0 && grafo[i][u] < 0) {
                // return -1;
            // }
        //    grafo[i][u] += minF;
            dam[u] -= minF;
            // if(dam[u] == 0) {
                // grafo[i][i] = 0;
            // }
            if(dam[u] < 0)
                return -1;
        }
        // cout << "lim" << lim << endl;
        maxF += minF;
    }
    // cout << "maxF" << maxF << ' ' << floe[s].first << endl;
    return maxF;
}

int max_flow() {
    int maxf = 0;
    for(int i = 0; i < n; ++i) {
        dam[i] = floe[i].second;
    }

    for(int i = 0; i < n; ++i) {
        if(i != t) {
            s = i;
            // cout << "comecou " <<  i << ' ' << s  << endl;
            int p = flow();
            // cout << "flow: p >" << p << endl;
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
    cout << pos.size() << endl;
    for(int i = 0; i < (int)pos.size()-1; ++i) {
        for(int j = i + 1; j < (int)pos.size(); ++j) {
                cout << "Aqui " <<  i << ' ' << j << endl;
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
        memset(grafoB, 0, sizeof(grafoB));
        cin >> n >> d;
        for(int j = 0; j < n; ++j) {
            cin >> x >> y >> n_penguens >> damage;
            total_peguens += n_penguens;
            pos.pb(make_pair(x, y));
            floe.pb(make_pair(n_penguens, damage));
        }
        // if(g != 11)
            // continue;
        contruct_graph();
        int flag = 0;
        // cout << g << ' ' << endl;
        for(int i = 0; i < n; ++i) {
            t = i; // end
            for(int l = 0; l < n-1; ++l) {
                for(int k = l+1; k < n; ++k) {
                    grafo[l][k] = grafoB[l][k];
                    // cout << grafo[l][k] << ' ';
                }
                // cout << endl;
            }
            int p = max_flow() + floe[t].first;
            // cout << p << " == " << dam[t] << "  " << total_peguens << endl;
            // return 0;
            if(p == total_peguens) {
                flag = 1;
                // cout << i << ' ';
            }
            // cout << "p> " << p << " = " << total_peguens << endl;
        }
        // if(flag) 
        //     cout << '\n';
        // else {
        //     cout << "-1\n";
        // }
        pos.clear();
        floe.clear();
    }
    return 0;
}