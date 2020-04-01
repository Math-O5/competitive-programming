/*
    Kruscal implementado com Union-Find.
*/
#include <iostream>
#include<queue>
#include<algorithm>
#define MAX 124752

using namespace std;

struct Aresta {
    int x, y, w;
    Aresta()
    {}
    Aresta(int x_, int y_, int w_)
    {
        x = x_;
        y = y_;
        w = w_;
    }
};

Aresta aresta[MAX];
int pai[501], peso[501];
int n, m, a, b, c, sum;

int find(int x)
{
    if(pai[x]==x)
        return x;
    return pai[x] = find(pai[x]);
}

void join(int x, int y)
{
    x = find(x);
    y = find(y);

    if(peso[x] > peso[y])
    {
        pai[y] = x;
    } else if(peso[y] > peso[x]){
        pai[x] = y;
    } else {
        pai[x] = y;
        peso[y]++;
    }
}

bool comp(Aresta a, Aresta b)
{
    return (a.w < b.w)? true : false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i<= n; ++i)
        pai[i] = i;
    for(int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        Aresta aux(a, b, c);
        aresta[i] = aux;
    }
    sort(aresta, aresta + m, comp);
    for(int i = 0; i < m; ++i)
    {
        int u = find(aresta[i].x), v = find(aresta[i].y);
        if(u != v)
        {
            join(u, v);
            sum += aresta[i].w;
        }
    }

    cout << sum << '\n';
    return 0;
}
