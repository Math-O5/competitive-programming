#include<iostream>
#include<map>
#include<string>
#include<queue>
#include<vector>
#include<functional>
#include<string.h>

using namespace std;

#define MAXN 3

int maxP = 0;

/**
 * Estado do jogo
 */ 
struct State {
    // string state;
    vector<vector<int>> state;
    string solucao;
    int profundidade, x, y;

    State() {}
    State(vector<vector<int>> state, int x, int y, 
            int profundidade, string solucao) 
            :
            state(state), profundidade(profundidade), 
            x(x), y(y), solucao(solucao) {}

};

/*
    Calcula quão longe está da resposta. quantas posições tão fora do lugar.
    Score 1 se for diferente 
    Score 0 se for igual
*/

/*
    Indice valido
*/
bool valid(int i) {
    return (i >= 0 && i <= 8);
}

bool valid(int i, int j) {
    return (i >= 0 && i < 3) && (j >= 0 && j < 3);
}

string tabelaToString(const vector<vector<int>>& tab) {
    string formated = "";
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            formated.append(to_string(tab[i][j]));
        }
    }
    return formated;
}

/*
    Troca duas peças de posição.

*/
vector<vector<int>> swapping(vector<vector<int>> tab, int x, int y, int x1, int y1) {
    int tmp = tab[x][y];
    tab[x][y] = tab[x1][y1];
    tab[x1][y1] = tmp; 
    return tab; 
}

int distanceSolution(const vector<vector<int>>& state, const vector<vector<int>>& final) {
    int ans = 0;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            ans += (state[i][j] != final[i][j]);
        }
    }
    return ans;
}

struct compPq {
    bool operator()(pair<int, State> const& p1, pair<int, State> const& p2) {
        return p1.first > p2.first;
    }
};

/*
    A tabela 
    
    1 2 3
    4 5 6
    7 8 X
*/
int d = 0;
void bfs(const State& inicial, const State& final) {

    // int moves[4][2] = {0,1,1,0,0,-1,-1,0}; // calcula o próximo movimento direita, baixo, esquerda, cima
    // char movesChar[4] = {'r','d','l','u'}; // movimentos possiveis
    int moves[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    char movesChar[4] = {'l', 'r', 'u', 'd'};
    map<string, bool> visitados;
    priority_queue<pair<int, State>, vector<pair<int, State>>, compPq> processando;

    if(!distanceSolution(inicial.state, final.state)) {
        // cout << "0\n";
        return;
    }

    processando.push(make_pair(0, inicial));

     while(!processando.empty()) {
        State atual = processando.top().second;
        processando.pop();

         // Testa os quadro lados
        for(int i = 0; i < 4; ++i) {
             int new_pos_x = atual.x + moves[i][0],              // calcula o proximo deslocamento horizontal
                 new_pos_y = atual.y + moves[i][1];              // calcula o proximo deslocamento vertical
                 string solucao = atual.solucao + movesChar[i]; // adiona o passo para a solução


            if(!valid(new_pos_x, new_pos_y) || !valid( atual.x,  atual.y)) 
                continue;

            //cout << new_pos_x << ' ' << new_pos_y << ' ' << atual.x << ' ' << atual.y << endl;

            // Gera o novo estado
            vector<vector<int>> new_state = swapping(atual.state, atual.x, atual.y, new_pos_x, new_pos_y);
            string str_new_state = tabelaToString(new_state);

            // Verifica se a posição é valida ou se já foi visitada
            if(!visitados[str_new_state]) {
                int score = distanceSolution(new_state, final.state);

                // Se atingiu o score 0, então todas peças estão no lugar certo.
                if(!score) {
                    // cout << "Score!" << endl;
                    // cout << str_new_state << endl;
                    // return State(new_state, new_pos_x, new_pos_y, atual.profundidade + 1, solucao);
                    cout << solucao << endl;
                    return;
                }

                // Função heuristica
                int f = score + atual.profundidade + 1;
                visitados[str_new_state] = true;
                processando.push(make_pair(f,
                            State(new_state, new_pos_x, new_pos_y, atual.profundidade + 1, solucao)));
            } 

        }
    }

    cout << "unsolvable \n";
    // visitados.clear();
    // return inicial;
}

/*
    Inicializa o vetor de vetores 3 x 3.

    stateStr : 1 2 3 4 5 6 7 8 9 
*/
vector<vector<int>> inicializa(string stateStr) {
    vector<vector<int>> state;
    int k = 0;
    for(int i = 0; i < 3; ++i) {
        vector<int> v;
        for(int j = 0; j < 3; ++j) {
            v.push_back((int)(stateStr[k]-'0'));
            ++k;
        }
        state.push_back(v);
    }

    return state;
}

/*
    A tabela 
    
    1 2 3
    4 5 6
    7 8 X

    (x, y) é a posição inciial do X(9)
*/
void solve(string stateInicial, int x, int y, string stateFinal, int x1, int y1) {
    State inicial(inicializa(stateInicial), x, y, 0, ""), final(inicializa(stateFinal), x1, y1, 0, "");
    bfs(inicial, final);

    // cout << answer.solucao << ' ' << answer.profundidade << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    char aux;
    string s = "";
    int x, y, n;
    cin >> n;
    for(int i = 0; i< n; ++i) {
        getchar();
        for(int i = 0; i < 9; ++i) {
            cin >> aux;
            if(aux == 'x') {
                x = i/3;
                y = i%3;
                aux = '9';
            }
            s.push_back(aux);
        }
        // cout << s << ' ' << x << ' ' << y << endl;
        solve(s, x, y, "123456789", 2, 2);

        cout << '\n';
    }
    return 0;
}