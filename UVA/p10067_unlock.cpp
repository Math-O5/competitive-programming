#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>
#include<map>
#include<string>
#include<string.h>

using namespace std;

struct State {
    int first, second, third, forth, g, moveSum;
    State(int first, int second, int third, int forth, int g) :
        first(first), second(second), third(third), forth(forth), g(g)
        {}
};

int forb[10000];

//map<string, int> forbidden;
int n, m, display[4], unlock[4];
int moves[8][4] = {
    { 1, 0, 0, 0},  
    { 0, 1, 0, 0},
    { 0, 0, 1, 0},
    { 0, 0, 0, 1},
    { 0, 0, 0,-1},
    { 0, 0,-1, 0},
    { 0,-1, 0, 0},
    {-1, 0, 0, 0}
};

struct compPq {
    bool operator()(pair<int, State> const& p1, pair<int, State> const& p2) {
        return p1.first > p2.first;
    }
};

bool valid(string ask) {
    int index = stoi(ask);
    if(forb[index]==0)
    {   
        forb[index] = 1;
        return true;
    }
    return false;
}

char toChar(int num)
{
    return char(num)+'0';
}

string arrayToString(State s)
{
    string r;
    r.push_back(toChar(s.first));
    r.push_back(toChar(s.second));
    r.push_back(toChar(s.third));
    r.push_back(toChar(s.forth));
    return r; 
}

int nearestUnlock(State v)
{
    return min(abs(v.first-unlock[0]), (10+min(v.first, unlock[0]) - max(v.first,unlock[0]))) +
           min(abs(v.second-unlock[1]), (10+min(v.second, unlock[0]) - max(v.first,unlock[1]))) + 
           min(abs(v.third-unlock[2]), (10+min(v.third, unlock[0]) - max(v.first,unlock[2]))) +
           min(abs(v.forth-unlock[3]), (10+min(v.forth, unlock[0]) - max(v.first,unlock[3])));
}

// validacao
int next(int x) {
    if( x < 0) x = 9;
    if( x > 9) x = 0;
    return x;
}
/*
    f = h + g
    h = the nearst answer
    g = the lower lv
*/ 
vector<int> ans;
void openLock() {
    
    // pq <f, safe states>
    // priority_queue<pair<int, State>, vector<pair<int, State>>, compPq> pq;
    queue<State> q;
    State aux(display[0], display[1], display[2], display[3], 0);

    aux.moveSum = 0;
    
    // pq.push(make_pair(0,aux));
    q.push(aux);
    forb[stoi(arrayToString(aux))] = 1;

    int h = nearestUnlock(aux);
    if(h == 0) {
        cout << "0\n";
        return;
    }
    while(!q.empty())
    {
        State u(q.front());
        int g = u.g;
        //cout << u.first << u.second << u.third << u.forth << u.g;
        q.pop();

        for(int i = 0; i < 8; ++i)
        {
            State v(next(u.first + moves[i][0]), next(u.second + moves[i][1]), next(u.third + moves[i][2]), next(u.forth + moves[i][3]), u.g+1);        
            if(valid(arrayToString(v)))
            {
                h = nearestUnlock(v);
                if(h == 0) {
                    ans.push_back(g+1);
                    //return;
                }
                int f = (g+1)+h;
                //cout << f << ' ' << g << ' ' << h << " --- ";
                q.push(v);
            }
        }
    }
    while (!q.empty())
    {
        q.pop();
    }
    
    if(ans.size())  
    {
        // sort(ans.begin(), ans.end());
        cout << ans[0] << '\n';
    }else
        cout << -1 << '\n';
    return;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            cin >> display[j];
        }
        for(int j = 0; j < 4; ++j)
        {
            cin >> unlock[j];
        }
        cin >> m;
        string aux;
        int c;
        for(int j = 0; j < m; ++j)
        {
            aux = "";
            for(int l = 0; l <4; ++l)
            {
                cin >> c;
                aux.append(to_string(c));
            }   
            forb[stoi(aux)] = 1;
        }

        openLock();
        ans.clear();
        memset(forb, 0, 10000*sizeof(int));
    }

    return 0;
}