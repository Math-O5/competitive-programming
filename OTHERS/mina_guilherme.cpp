// Guilherme A. Pinto, OBI-2015, mina

#include <iostream>
#include <queue>

#define MAX 100
#define INF 100000

using namespace std;

struct Elemento {
  int i, j, d;
  Elemento( int ai, int aj, int ad ) :
    i(ai), j(aj), d(ad) {};
};
struct Cmp {
  bool operator()( Elemento& lhs, Elemento& rhs) {
    return lhs.d > rhs.d;
  }
};
struct Quadrado { int v,d; bool m; };

priority_queue< Elemento, vector<Elemento>, Cmp > q;
Quadrado mina[MAX][MAX];
int N;

int d[5] = {0,1,0,-1,0};

int main(){
  int a, b;
  
  cin >> N;
  for( int i = 0; i < N; i++ )
    for ( int j = 0; j < N; j++ ){
      cin >> mina[i][j].v;
      mina[i][j].d = INF;
      mina[i][j].m = false;
    }

  // Dijkstra
  
  mina[0][0].d = 0;
  q.push( Elemento( 0, 0, 0 ) );

  while( !q.empty() ){
    Elemento f = q.top();
    if ( !mina[f.i][f.j].m ){
      mina[f.i][f.j].m = true; mina[f.i][f.j].d = f.d;
      if ( f.i == N-1 && f.j == N-1 ) break;
      // para cada movimento ortogonal
      for ( int k = 0; k < 4; k++ ){
	a = f.i + d[k]; b = f.j + d[k+1];
	if ( a >= 0 && a < N && b >= 0 && b < N && !mina[a][b].m )
	  q.push( Elemento( a, b, f.d + mina[a][b].v ) );
      }
    }
    q.pop();
  }
  
  cout << mina[N-1][N-1].d << endl;
  
  return 0;
}
