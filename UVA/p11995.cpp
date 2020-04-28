#include<iostream>
#include<stack>
#include<queue>

using namespace std;

queue<int> q;
stack<int> s;
priority_queue<int>pq;
int typeData[3] = {0};

int main() {
    int n, a, b;

    while(scanf("%d", &n) != EOF)
    {
        while(n--) {
            scanf("%d%d", &a, &b);
            switch(a) 
            {
                case 1:
                    q.push(b);
                    s.push(b);
                    pq.push(b);
                break;
                case 2:
                    typeData[0] = (typeData[0] != -1 && q.front() == b)? 1 : -1;
                    typeData[1] = (typeData[1] != -1 && s.top() == b)? 1 : -1;
                    typeData[2] = (typeData[2] != -1 && pq.top() == b)? 1 : -1;
                    q.pop();
                    s.pop();
                    pq.pop();
                break;
            }
        }
        if( (typeData[0]==1 && (typeData[1]==1 || typeData[2]==1)) || 
            (typeData[1]==1 && (typeData[0]==1 || typeData[2]==1)) || 
            (typeData[2]==1 && (typeData[0]==1 || typeData[1]==1)))
        {
            printf("not sure\n");
        } else if(typeData[0]==1) {
            printf("queue\n");
                
        } else if(typeData[1]==1) {
            printf("stack\n");
        } else if(typeData[2]==1) {
            printf("priority queue\n");
        } else
            printf("impossible\n");
        
        while (!s.empty())
        {
            s.pop();
        }
        
        while (!q.empty())
        {
            q.pop();
        }
        
        while(!pq.empty()) {
            pq.pop();    
        }
        typeData[0] = 0;
        typeData[1] = 0;
        typeData[2] = 0;
    }
    
    return 0;
}