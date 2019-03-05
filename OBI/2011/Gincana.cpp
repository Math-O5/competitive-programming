#include<bits/stdc++.h>


using namespace std;



#define maxn 10000


int visitados[maxn];
vector<int> lis[maxn];

int n, m;

void BFS(int s)
{
    
    queue<int> fila;
    fila.push(s);
    visitados[s]  = 0;

    while(!fila.empty())
    {
       int u = fila.front();
       
       fila.pop();
       
       for(int i = 0; i < (int)lis[u].size(); ++i)
       {
         int v = lis[u][i];
         
         if(visitados[v] == -1)
         {
             fila.push(v);
              visitados[v]  = visitados[u];
             
             
         }
        
       }
    }
    
}

int main(){
    
 memset(visitados, -1, sizeof(int)*maxn);
 
 int go, to;
 cin >> n >> m;
 
 for(int i = 1; i <= m; ++i)
 {
     cin >> go >> to;
     lis[go].push_back(to);
     lis[to].push_back(go);
     
 }
 
 BFS(1);
 int componente = 1;
 
 for(int i = 2; i <= n; i++)
 {
   if(visitados[i] == -1)
   {
        BFS(i);
       ++componente;
   }
     
 }
 
 cout << componente << '\n';
 
 return 0;
}