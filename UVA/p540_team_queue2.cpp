#include<iostream>
#include<deque>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include <utility>  

using namespace std;

int n, x, aux;
deque<pair<int,deque<int>>> fila;
deque<pair<int, deque<int>>> team;
//vector<queue<int>> vq;
//map<pair<int, int>, int> team;

int findNext() {
    int id = -1;
    for(auto ptr = fila.begin(); ptr < fila.end(); ++ptr) 
    {
        if(!ptr->second.empty() && ptr->second.front() == x) 
        {
            ptr->second.pop_front();
            id = ptr->first;
            // if(ptr->second.empty()) { //erase
            //     ptr = ptr + 1;
            // }
            return id;
        }
    }  
    return -1;
}

void enqueue() {
    cin >> x;
    int idTeam = findNext();
    if(!team.empty())
    {
        for(auto ptr = team.begin(); ptr < team.end(); ++ptr) 
        {
            if(ptr->first == idTeam) 
            {
                ptr->second.push_back(x);
                return;
            } 
        }
        deque<int> d;
        d.push_back(x);
        team.push_back(make_pair(idTeam, d));
    } else {
        deque<int> d;
        d.push_back(x);
        team.push_back(make_pair(idTeam, d));
    }
    return;
}

void dequeue() {
    
    if(team.empty()) return;
    
   
    if(!team.begin()->second.empty()) 
    {
        // cout << "front " << team.begin()->second.front() << endl;
        // cout << "size " << team.begin()->second.size() << endl;
        cout << team.begin()->second.front() << endl;
        team.begin()->second.pop_front();

        if(team.begin()->second.empty()) { //erase
            team.pop_front();
        }
        return;
    }
     
    return;
}

void getTeam() {
    for(int i = 0; i < n; ++i) {
        cin >> x;
        deque<int> filaAux;
        for(int j = 0; j < x; ++j) {
            cin >> aux;
            filaAux.push_back(aux);
        }
        fila.push_back(make_pair(i, filaAux));
    }
}

void reset(deque<pair<int, deque<int>>>&geral) {
    if(!geral.empty())
    {
        auto ptr = geral.begin();
        while( ptr < geral.end()) 
        {
            while(!ptr->second.empty()) {
                //cout << "reset " <<ptr->second.front();
                ptr->second.pop_front();
            }
            geral.pop_front();
            ptr = geral.begin();
        }
    }
}

int main() {
    string s;
    int i = 1;
    while(cin >> n && n > 0) {
        int stop = 0;
        cout << "Scenario #" << i++ << endl;
        getTeam();
        
        while(!stop) {
            cin >> s;
            switch(s[0]) {
                case 'E':
                    enqueue();
                break;
                case 'D':
                    dequeue();
                break;
                case 'S':
                    stop = 1;
                break;
            }
        }
        cout << '\n';
        reset(team);
        reset(fila);
    }
    return 0;
}


