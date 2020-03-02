#include<iostream>
#include<queue>
#include<vector>
#define MAX 100009
using namespace std;

int n, m, k, aux, x, ans;
priority_queue<pair<int, int >> pq;
int sizeBox[MAX];
vector<int> buff[MAX];

int main(int argc, char *argv[])
{
	cin >> n >> m >> k;
	// 1 index
	for(int i = 1; i <= n; ++i)
	{
		cin >> sizeBox[i];
	}
	for(int i = 1; i <= n; ++i)
	{
		cin >> x;
		for(int j = 0; j < x; ++j)
		{
		  	cin >> aux;
		      buff[i].push_back(aux);
		}
		if(!x)
		     buff[i].push_back(0);
	}
	for(int i = 0; i < m; ++i)
	{
		cin >> aux;
		pq.push(make_pair(sizeBox[aux], aux));
	}
	for(int i = 0; i < k; ++i)
	{
		pair<int, int> m = pq.top();
		pq.pop();
		 if(buff[m.second][0]==0) {
		 	++ans;
		 } else {
		 	for(int j = 0; j < (int)buff[m.second].size(); ++j) {
		 		pq.push(make_pair(sizeBox[buff[m.second][j]], buff[m.second][j] ));
		 	}	 	 
		 }
	}
	cout << ans << '\n';
	return 0;
}