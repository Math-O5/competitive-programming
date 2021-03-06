#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h> // memset
#include <algorithm> // lower_bound
#include <iomanip>
#include <bitset>
    // #include <bits/stdc++.h>

using namespace std;

#define NMAX 50155
int INF = (int) 1e9;

int n, m, sink, terminal;
vector<vector<pair<int,pair<int,int> > > >adj;
vector<pair<int,int> > edges;
vector<pair<int,int> > node;
vector<pair<int,int> > st;
int mark[NMAX];
int idx[NMAX];
int par[NMAX];
int rel[NMAX];
int tot;
int cnt;

int augment_path(int v, int mf){
 if(v == sink){
  //printf("%d ", v);
  return mf;
 }
 int u = par[v];
 int k = rel[v];
 int m = adj[u][k].second.first;
 int n = adj[u][k].second.second;
 bool back_edge = false;
 if(edges[m].first == 0) back_edge = true;
 if(back_edge){
  mf = min(mf, edges[n].second);
 } else {
  mf = min(mf, edges[m].first - edges[m].second);
 }
 mf = augment_path(u, mf);
 //printf("%d ", v);
 if(back_edge){
  edges[n].second -= mf;
 } else {
  edges[m].second += mf;
 }
 return mf;
}

bool edmond_karps(){
 int maxflow = 0;
 while(1){
  bool can_augment = false;
  for(int i=0;i<cnt;++i) par[i] = -1;
  par[T] = -1;
  queue<int> q;
  q.push(S);
  par[S] = S;
  while(!q.empty()){
   int u = q.front();
   q.pop();
   for(int i=0;i<adj[u].size();++i){
    int v = adj[u][i].first;
    int m = adj[u][i].second.first;
    int n = adj[u][i].second.second;
    if(par[v] != -1) continue;
    if(edges[m].first - edges[m].second > 0 ||
       edges[n].second > 0) {
     par[v] = u;
     rel[v] = i;
     if(v == T) {
      can_augment = true;
      break;
     } else {
      q.push(v);
     }
    }
   }
   if(can_augment) break;
  }
  if(can_augment){
   maxflow += augment_path(T, INF);
   //printf("\n");
   if(maxflow == tot) break;
  } else {
   break;
  }
 }
 return (maxflow == tot);
}

void add_edge(int u, int v, int cap) {
    adj[u].push_back(make_pair(v, make_pair(edges.size(), edges.size()+1)));
    adj[v].push_back(make_pair(u, make_pair(edges.size()+1, edges.size())));
    edges.push_back(make_pair(cap, 0));
    edges.push_back(make_pair(0, 0));
}


int main() {
    int tc = 1;
    int v, s, t;
    while(cin >> n, n > 0){
    cin >> m;
    node = vector<pair<int,int> > (NMAX);
    adj = vector<vector<pair<int, pair<int,int> > > > (NMAX);
    edges.clear();
    st.clear();
    sink = NMAX-2;
    terminal = NMAX-1;
    tot = 0;
    memset(mark, 0, sizeof(mark));
    for(int i = 0; i < n; ++i) {
        cin >> v >> s >> t;

        // add edge between sin and monkey of cost v
        add_edge(sink, i, v);
        st.push_back(make_pair(s,t));
        tot += v;
        mark[s] = 1;
        mark[t] = 1;
    }
    cnt = n;

    // split interval
    int prev = -1;
    for(int j = 0; j <= 50000; ++j) {
        if(mark[j]) {
            if(prev == -1) {
                prev = j;
            } else {
                node[cnt] = make_pair(prev,j);
                idx[prev] = cnt;
                add_edge(cnt, terminal, (j - prev)*m);
                prev = j;
                ++cnt;
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=st[i].first;j<st[i].second;++j){
            if(mark[j]){
            add_edge(i, idx[j], node[idx[j]].second - node[idx[j]].first);
            //printf("%d, [%d,%d], %d\n", j, node[idx[j]].first, node[idx[j]].second, node[idx[j]].second - node[idx[j]].first);
            }
        }
    }

    if(edmond_karps()){
    printf("Case %d: Yes\n", tc++);
    int tracker[50050];
    memset(tracker, 0, sizeof tracker);
    for(int i=0;i<N;++i){
    vector<pair<int,int> > itv;
    for(int j=0;j<adj[i].size();++j){
        if(adj[i][j].first == T || adj[i][j].first == S) continue;
        int v = adj[i][j].first;
        int m = adj[i][j].second.first;
        //printf("%d --> %d [%d,%d]\n",i, edges[m].second, node[v].first, node[v].second);
        if(edges[m].first > 0 && edges[m].second > 0) {
        int start = node[v].first + tracker[v];
        int end = node[v].first + tracker[v] + edges[m].second;
        if(end > node[v].second){
        int _end = end - (node[v].second - node[v].first);
        tracker[v] = _end - node[v].first;
        if(!itv.empty() && itv.back().second == node[v].first){
        itv.back().second = _end;
        } else {
        itv.push_back(make_pair(node[v].first, _end));
        }
        if(_end == start){
        itv.back().second = node[v].second;
        } else {
        itv.push_back(make_pair(start, node[v].second));
        }
        } else {
        tracker[v] = end - node[v].first;
        if(tracker[v] == (node[v].second - node[v].first)) tracker[v] = 0;
        if(!itv.empty() && itv.back().second == start){
        itv.back().second = end;
        } else {
        itv.push_back(make_pair(start, end));
        }
        }
        }
    }
    printf("%d", (int) itv.size());
    for(int j=0;j<itv.size();++j){
        printf(" (%d,%d)", itv[j].first, itv[j].second);
    }
    printf("\n");
    }
    } else {
    printf("Case %d: No\n", tc++);
    }
    }
    return 0;
}