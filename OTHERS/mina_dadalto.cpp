/****************************************************************************
 * Arthur Pratti Dadalto
 * OBI 2015 - Mina
 * "0-1 BFS"
 ***************************************************************************/

#include <stdio.h>
#include <deque>
using namespace std;

int a[1123*1123], d[1123*1123];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int
main(void)
{
	int n, cur;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &a[i*n + j]);
	deque<int> q;
	q.push_back(0);
	d[0] = 1;
	while(!q.empty())
	{
		cur = q.front();
		q.pop_front();
		for(int i = 0; i < 4; i++)
			if((cur % n) + dy[i] < n && (cur % n) + dy[i] >= 0 && cur + dx[i]*n + dy[i] < n*n && cur + dx[i]*n + dy[i] >= 0 && d[cur + dx[i]*n + dy[i]] == 0 )
			{
				d[cur + dx[i]*n + dy[i]] = d[cur] + a[cur + dx[i]*n + dy[i]];
				if(a[cur + dx[i]*n + dy[i]] == 0)
					q.push_front(cur + dx[i]*n + dy[i]);
				else
					q.push_back(cur + dx[i]*n + dy[i]);
			}
	}
	printf("%d\n", d[n*n-1] - 1);
}