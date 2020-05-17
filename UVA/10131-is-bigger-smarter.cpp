// problem:
// https://s3-us-west-2.amazonaws.com/prod-runcodes-files/exercisefiles/14552/p10131.pdf?X-Amz-Content-Sha256=e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855&X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAI3OUHGVPPSQMGO5Q%2F20200517%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20200517T182414Z&X-Amz-SignedHeaders=Host&X-Amz-Expires=120&X-Amz-Signature=ec4ec7d41dde38e46f3cb6a81112e5a8fca7a722dbe9ba4602681a0bb5712fb8
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h> // memset
#include <algorithm> // lower_bound
#include <bitset>

using namespace std;

#define fs first
#define sd second
#define pb push_back
// #define mp make_pair
#define MAXN 100001

const int INF = 0x3f3f3f3f;
//priority_queue<pair<int, vector<pair<int, int>>>> elem;
#define M 10001

struct Elephant{
    int id,
        w,
        s;
};

bool mySort(const Elephant& a, const Elephant& b){
    return (a.w != b.w)? (a.w < b.w) : (a.s > b.s);
}

bitset<MAXN> dp;
Elephant elem[MAXN];


int lis(int n) {
    vector<pair<int, int>> v;
    vector<int> topo,   // QI
                ans;    // subsequence of elephantes
    vector<int>::iterator it;
    int ultimoTopo;

    /*************************/
    // primeira iteração, inicializa topo

    //cout << v[0].first << ' ' << v[0].second << endl;

    // armazeno as tres informações ordenadas pelo maior peso
    topo.pb(elem[0].s);
    ultimoTopo = topo.back();
    /*************************/

    for(int i = n - 1; i >= 0; --i) {
        // procuro a maior subsequencia crescente em QI
        it = lower_bound(topo.begin(), topo.end(), elem[i].s);
        // se o peso ainda nao foi escolhido
        if(!dp[elem[i].w]) {
            // crio uma nova pilha se o elemnto eh maior que o topo das anteriores
             if(it == topo.end()) {
                 dp[elem[i].w] = 1; // marco o peso como escolhido
                 ans.pb(topo.back()); // o topo da ultima pilha faz parte da subsequencia
                 topo.pb(elem[i].s); // topo da nova pilha
                 ultimoTopo = elem[i].s; // o ultimo elemento da sequencia 
             } else {
                 *it = elem[i].s; // atualizo topo
             }
        }

    }

    // ultima iteração, atualiza resposta
    ans.pb(ultimoTopo);

    //reverse(ans.begin(), ans.end());
    
    // o tamanho da sequencia é
    cout << (int)topo.size() << endl;

    // a sequencia é
    int i = 0; 
    while(ans.size()) {
        int qi = ans.back();
        while(i < n) {
            if(elem[i].s == qi) {
                cout << elem[i].id << endl;
                break;
            }
            ++i;
        }
        ans.pop_back();
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = 0, a, b, i = 0;
    while(cin >> elem[n].w >> elem[n].s) {
        elem[n].id = n + 1; 
        ++n;
    }

    lis(n);

    return 0;
}