
#include<bits/stdc++.h>

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
                    q.push(a);
                    s.push(a);
                    pq.push(a);
                break;
                case 2:
                    typeData[0] = (q.top() == b);
                    typeData[1] = (s.top() == b);
                    typeData[3] = (pq.top() == b);
                    q.pop();
                    s.pop();
                    pq.pop();
                break;
            }
        }
    }

    
    if( (typeData[0]==1 && (typeData[1] || typeData[2])) || 
        (typeData[1]==1 && (typeData[0] || typeData[2]))) || 
        (typeData[2]==1 && (typeData[0] || typeData[1])))
    {
            printf("not sure");
    } else if(typeData[0]==1) {
        printf("queue");
            
    } else if(typeData[1]==1) {
        printf("stack");
    } else if(typeData[2]==1) {
        printf("priority queue");
    } else
        printf("impossible");
    
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
    
    return 0;
}
