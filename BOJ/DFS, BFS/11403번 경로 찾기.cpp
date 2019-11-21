#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

const int MAX = 100 + 1;

int Map[MAX][MAX];
int N;
int visited[MAX];

int BFS(int start, int end)
{
	queue<int> q;
	q.push(start);
	
	int ret = 0;
	
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		for(int i = 1; i <= N; i++)
		{
			if(Map[x][i] == 1 && visited[i] == 0)
			{
				q.push(i);
				visited[i] = 1;
				if(i == end)
				{
					ret = 1;
					break;
				}
			} 
		}
	}
	
	return ret;
}
int main(void)
{
	
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			printf("%d ", BFS(i, j));
			memset(visited, 0, sizeof(visited));
		}
		printf("\n");
	}
	
	return 0;
}
