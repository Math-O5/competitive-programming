#include<iostream>
#include<map>
#include<string>
#include<queue>
#include<vector>
#include<functional>
#define For(i, a, b) for(int i = a; i <= b; ++i)
using namespace std;

int n, table[3][3], moves[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}, x, y;
char movesChar[4] = {'r','d','l','u'};
map<string, bool> vis;
string s, v;

struct State {
    string state, ans;
    int g;

    State(string state, string ans, int g) : state(state), ans(ans), g(g)
    {}
};

struct compPq {
    bool operator()(pair<int, State> const& p1, pair<int, State> const& p2) {
        return p1.first > p2.first;
    }
};

string matrixToString()
{
    string u = "";
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            u.push_back(char(table[i][j]+'0'));
        }
    }
    //cout << "aaaa\n";
    //cout << u << '\n';
    return u;
}


void stringToMatrix(string& b)
{
    //cout << "here\n";
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            table[i][j] = int(b[i*3 +j]-'0');
            // cout << table[i][j];
            if(table[i][j]==9) {
                x = i; y = j;
            }
        }
    }
    //cout << '\n';
}

int solutionFar(string& v1) {
    int ans = 0;
    for(int i = 0; i < 9; ++i)
        ans += abs(v1[i]-char(i+1+'0'));
    return ans;
}

bool valid(int i, int j) {
    return (i >= 0 && j >= 0 && j < 3 && i < 3);
}

string swapMatrix(int x1, int y1) 
{
    //cout << "swap" << table[x][y] << "  " << table[x1][y1] << endl;
    swap(table[x][y], table[x1][y1]);
    //cout << "swap" << table[x][y] << "  " << table[x1][y1] << endl;

    string b = matrixToString();
    swap(table[x][y], table[x1][y1]);
    return b;
}

void bfs()
{
    // f = g + h
    s = matrixToString(); 
    State stateA(s,"", 0);
    priority_queue<pair<int, State>, vector<pair<int, State>>, compPq> pq;
    pq.push(make_pair(0, stateA));
    vis[s] = true;

    while(!pq.empty())
    {
        stateA = pq.top().second;
        //cout << "stateA "<< stateA.state << endl;
        pq.pop();
        stringToMatrix(stateA.state);
        for(int i = 0; i < 4; ++i)
        {
            int x1 = x + moves[i][0];
            int y1 = y + moves[i][1];
            if(valid(x1, y1))
            {
                v = swapMatrix(x1,y1);
                //cout << "cheguei " << v << ' ' << vis[v] << endl;
                if(!vis[v])
                {
                    vis[v] = true;
                    int h = solutionFar(v);
                    int f = h * (stateA.g + 1);
                    string c;
                    c.append(stateA.ans);
                    c.push_back(movesChar[i]);
                    if(h == 0)
                    {
                        cout << c << '\n';
                        return;
                    }
                    State stateB(v, c, stateA.g + 1);
                    pq.push(make_pair(f, stateB));
                }
            }
        }
    }
    cout << "unsolvable\n";

}

int main()
{
    string aux;
    cin >> n;
    for(int i = 0; i< n; ++i) {
        getchar();
        for(int j = 0; j < 3; ++j)
        {
            for(int k = 0; k < 3; ++k)
            {
                cin >> aux;
                if(aux[0] == 'x')
                    table[j][k] = 9;
                else
                    table[j][k] = aux[0] - '0';
            }
            

        }
        bfs();
        vis.clear();

        if(i < n -1) cout << '\n';
    }
    return 0;
}