#include<iostream>
#include<map>
#include<string>
#include<queue>
#include<vector>
#include<functional>
#include<string.h>

using namespace std;

#define MAXN 400000

struct compPq {
    bool operator()(pair<int, int> const& p1, pair<int, int> const& p2) {
        return p1.first > p2.first;
    }
};

struct State {
    string solucao;
    int state[9], pos, g;
};
int vis[MAXN];
int factor[9] = {1,1,2,6,24,120,720,5040,40320};
queue<int> q;
priority_queue<pair<int, int>, vector<pair<int, int>>, compPq> pq;
State states[MAXN];

int it = 0;

/**
 * Estado do jogo
 */ 

/*
    Calcula quão longe está da resposta. quantas posições tão fora do lugar.
    Score 1 se for diferente 
    Score 0 se for igual
*/

/*
    Indice valido
*/
bool valid(int i) {
    return (i >= 0 && i < 3);
}

bool valid(int i, int j) {
    return (i >= 0 && i < 3) && (j >= 0 && j < 3);
}

int distanceSolution(const State& final) {
    int ans = 0;
    for(int i = 1; i < 9; ++i) {
        ans += (final.state[i] != i);
    }
    return ans;


}

int cantorHash(int str[]){
    int i , j , temp , num;
    num = 0 ;
    for(i = 0 ; i < 9 ; i++){
        temp = 0;
        for(j = i+1 ; j < 9 ; j++){
            if(str[j] < str[i]) temp++;
        }  
        num += factor[8-i]*temp;
    }
    return num;   
}

void bfs(State& inicial) {
    int moves[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    char movesChar[4] = {'l', 'r', 'u', 'd'};
    //priority_queue<pair<int, State>, vector<pair<int, State>>, compPq> processando;
    while(!pq.empty())
        pq.pop();
        // ++it;
        // if(it > 100000) return;
    memset(vis, 0, sizeof(vis));

    int start = cantorHash(inicial.state);
    vis[start] = 1;
    // q.push(start);
    pq.push(make_pair(0, start));
    states[start] = inicial;

     while(!pq.empty()) {
        State atual = states[pq.top().second];
        pq.pop();

         // Testa os quadro lados
        for(int i = 0; i < 4; ++i) {
            int x = atual.pos/3;
            int y = atual.pos%3;

             int new_pos_x = x + moves[i][0],              // calcula o proximo deslocamento horizontal
                 new_pos_y = y + moves[i][1];              // calcula o proximo deslocamento vertical


            if(!valid(new_pos_x, new_pos_y)) 
                continue;

            //cout << new_pos_x << ' ' << new_pos_y << ' ' << atual.x << ' ' << atual.y << endl;

            State tmp = atual; 
            tmp.state[tmp.pos] = tmp.state[3*new_pos_x + new_pos_y];
            tmp.state[3*new_pos_x + new_pos_y] = 9;
            tmp.pos = 3*new_pos_x + new_pos_y;
            int hash = cantorHash(tmp.state);

            // Verifica se a posição é valida ou se já foi visitada
            if(!vis[hash]) {
                tmp.solucao.push_back(movesChar[i]); 
                // Se atingiu o score 0, então todas peças estão no lugar certo.
                int score = distanceSolution(tmp);
                //cout << score << ' ';
                if(!score || !hash) {
                    // cout << "Score!" << endl;
                    // cout << str_new_state << endl;
                    // return State(new_state, new_pos_x, new_pos_y, atual.profundidade + 1, solucao);
                    cout << tmp.solucao << endl;
                    return;
                }

                // Função heuristica
                vis[hash] = 1;
                tmp.g = atual.g + 1;
                //q.push(hash);
                pq.push(make_pair(score + tmp.g, hash));
                states[hash] = tmp;
            } 

        }
    }

    cout << "unsolvable \n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    State inicial;

    char aux;
    int x, y, n;
    cin >> n;
    for(int i = 0; i< n; ++i) {
        getchar();
        for(int i = 0; i < 9; ++i) {
            cin >> aux;
            if(aux == 'x') {
                inicial.pos = i;
                aux = '9';
            } 
            inicial.state[i] = aux - '0';
            
        }
        inicial.g = 0;
        bfs(inicial);

        cout << '\n';
    }
    return 0;
}