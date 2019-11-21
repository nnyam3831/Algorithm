#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>

using namespace std;

int visited[1001];
int N, M, V;
vector<int> v[1001];

void DFS(int X)
{
	printf("%d ", X);
	visited[X] = 1;
	for(int i = 0; i < v[X].size(); i++)
	{
		int y = v[X][i];
		if(visited[y] == 0)
		{
			visited[y] = 1;
			DFS(y);
		}
	}
}
void BFS(int X)
{
	queue<int> q;
	q.push(X);
	visited[X] = 1;
	while(!q.empty())
	{
		int k = q.front();
		q.pop();
		printf("%d ", k);
		for(int i = 0; i < v[k].size(); i++)
		{
			int y = v[k][i];
			if(visited[y] == 0)
			{
				visited[y] = 1;
				q.push(y);
			}
		}
	}
	
	printf("\n");
}
int main(void)
{
	cin >> N >> M >> V;
		
	for(int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i = 0; i < N; i++)
	{
		sort(v[i].begin(), v[i].end());
	}
	DFS(V);
	memset(visited, 0, sizeof(visited));
	printf("\n");
	BFS(V);
	
	return 0;
}
