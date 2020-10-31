#include<bits/stdc++.h>

#define MAXN 100000

using namespace std;

int n, moves[4][2] = {{0,1},{0,-1}, {1,0},{-1,0}},  pos;
char movesChar[4] = {'r','l','d','u'};

struct State {
    string state, ans;
    int g, pos;

    State(string state, int pos, string ans, int g) : state(state), pos(pos), ans(ans), g(g)
    {}
};

struct compPq {
    bool operator()(pair<int, State> const& p1, pair<int, State> const& p2) {
        return p1.first > p2.first;
    }
};

string res = "987654321";

string f = "123456789";

int solutionFar(string& v1) {
    int ans = 0;
    for(int i = 0; i < 9; ++i)
        ans += (v1[i] != f[i]);
    return ans;
}


bool valid(int i) {
    return (i >= 0 && i <= 8);
}

string swaping(string s, int a, int b) {
    char h;
    h = s[b];
    s[b] = s[a];
    s[a] = h;
    return s;
}

// int vis_hash[MAXN];
// const int prime = 131071;

// void compute_hash(string s) {
//     int seed = stoi(s);
//     vis_hash[seed] = 1;
// }

// bool isVisited(string s) {
//      int seed = 1*int(s[0]-'0') + 2*int(s[1]-'0') 
//                 + 3*int(s[2]-'0') + 4*int(s[3]-'0') + 5*int(s[4]-'0') +
//                  6*int(s[5]-'0') + 7*int(s[6]-'0') + 8*int(s[7]-'0') + 9*int(s[8]-'0');
//     return (vis_hash[seed] == 1);
// }

void bfs(string s) {
    // f = g + h 
    State stateA(s, pos, "", 0);

    priority_queue<pair<int, State>, vector<pair<int, State>>, compPq> pq;
    // map<string, bool> vis;
    vector<bool> vis(10000000000, false);

    pq.push(make_pair(0, stateA));
    vis[stoi(s)] = true;
    int h = solutionFar(s);
    if(h == 0)
    {
        cout << 0 << '\n';
        return;
    }
    while(!pq.empty())
    {
        stateA = pq.top().second;
        // cout << "stateA "<< stateA.state << ' ' << stateA.pos <<  endl;
        pq.pop();
        for(int i = 0; i < 4; ++i)
        {
            int tmp_pos = stateA.pos + (moves[i][0]*3) + moves[i][1];
            if(valid(tmp_pos))
            {
                // cout << stateA.state << endl;
                string tmp_state = swaping(stateA.state, stateA.pos, tmp_pos);
                // cout << stateA.state << ' ' << tmp_state << endl;
                //cout << "cheguei " << v << ' ' << vis[v] << endl;
                if(!vis[stoi(tmp_state)])
                {
                    vis[stoi(tmp_state)] = true;
                    h = solutionFar(tmp_state);
                    int f = h + (stateA.g);
                    string c;
                    c.append(stateA.ans);
                    c.push_back(movesChar[i]);
                    if(h == 0)
                    {
                        // cout << "Ordenado: " << stateA.state << endl;
                        cout << c << '\n';
                        return;
                    }
                    State stateB(tmp_state, tmp_pos, c, stateA.g + 1);
                    pq.push(make_pair(f, stateB));
                }
            }
        }
    }
    cout << "unsolvable\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    char aux;
    cin >> n;
    for(int i = 0; i< n; ++i) {
        string s;
        getchar();
        for(int j = 0; j < 9; ++j) {
            cin >> aux;
            if(aux == 'x') {
                pos = j;
                aux = '9';
            }
            s.push_back(aux);
        }

        bfs(s);
        s.clear();
        if(i < n -1) cout << '\n';
    }
    return 0;
}