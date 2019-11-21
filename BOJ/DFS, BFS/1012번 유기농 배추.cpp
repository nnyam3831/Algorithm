#include <iostream>
#include <queue>
#include <memory.h>
#define MAX 50 + 1

using namespace std;

int T;
int N, M, K;
int visited[MAX][MAX];
int Map[MAX][MAX];

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int bfs(int y, int x)
{
	if(Map[y][x] == 0 || visited[y][x] == 1) return 0;
	
	// 둘다 아니면 처음 접근하는 배추 
	int ret = 0;
	visited[y][x] = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));

	while(!q.empty())
	{
		
		pair<int, int> r = q.front();
		int curY = r.first;
		int curX = r.second;
		q.pop();
		
		for(int dir = 0; dir < 4; dir++)
		{
			int nextY = curY + dy[dir];
			int nextX = curX + dx[dir];
			
			if(nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) continue;
			if(visited[nextY][nextX] == 0 && Map[nextY][nextX] == 1)
			{
				visited[nextY][nextX] = 1;
				q.push(make_pair(nextY, nextX));
			}
		}
		
	}
	
	return ++ret;
}

int main(void)
{
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		int result = 0;
		memset(Map, 0, sizeof(Map));
		memset(visited, 0, sizeof(visited));
		cin >> M >> N >> K;
		for(int i = 0; i < K; i++)
		{
			int y, x;
			cin >> x >> y;
			Map[y][x] = 1;
		}
		
		
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < M; j++)
			{
				result += bfs(i, j);
			}
		}
		
		cout << result << "\n";
	}
	return 0;
}
