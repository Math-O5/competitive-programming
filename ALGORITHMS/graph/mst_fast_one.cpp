#include<iostream>
#include<queue>
#define MAX 100000
using namespace std;

const int INF = 0x3f3f3f3f;

priority_queue<Aresta, vector<Aresta>, comp> pq;

struct Aresta {
    int a, b, w;
    Aresta(int a, int b, int w): a(a), b(b), w(w) {}
};

struct comp {
    bool operator()(Aresta const& a, Aresta const& b) {
        return a.w > b.w;
    }
};

void kruskal()
{
    
}

int main() {
    return 0;
}