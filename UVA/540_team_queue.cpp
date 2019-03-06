#include <map>
#include<iostream>
#include <queue>
#define MAXN 1001

using namespace std;

map<int, int> player;
map<int, queue<int>> team_queue;
queue<int> seq;
int t, n, i, j;
char s[10];
int l = 0;
int main(){    
    while(scanf("%d",&t) && t){
        cout<<"Scenario #"<<++l<<endl;
        for(i=0;i<t;++i){
            scanf("%d",&n);
            while(n--){
                scanf("%d",&j);
                player[j] = i;
            }
        }
        while(scanf("%s",s) && s[0]!='S'){
            if(s[0] =='E'){
                scanf("%d",&n);
                if(team_queue[player[n]].empty()){
                  seq.push(player[n]);
                }
                team_queue[player[n]].push(n);
            } 
            else {
                while(team_queue[seq.front()].empty())
                    {if(!seq.empty()) seq.pop();} 
                printf("%d\n",team_queue[seq.front()].front());
                team_queue[seq.front()].pop(); 
                if(team_queue[seq.front()].empty())
                    {team_queue.erase(seq.front()); seq.pop();}
        
            }
        }
        while(!seq.empty()) {
            int x = seq.front();
            while(!team_queue[x].empty()){
                team_queue[x].pop();
            }
            seq.pop();
        }
        cout<<endl;
        player.clear();
    }
    return 0;    
}