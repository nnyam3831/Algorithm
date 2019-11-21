#include <iostream>
#include <vector>
#include <queue>

#define MAX 1000 + 1
using namespace std;

struct Tom{
	int y, x;
	int Count;
};

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int visited[MAX][MAX];
int N, M, ans;
int Tomato[MAX][MAX];

int bfs()
{
	int count;
	queue<Tom> q;
	
	// 일단 처음에 익은 토마토 큐에 다 넣고 
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(Tomato[i][j] == 1)
			{
				Tom temp;
				temp.y = i;
				temp.x = j;
				temp.Count = 0;
				q.push(temp);
				visited[i][j] = 1;
			}
		}
	}
	
	// bfs 돌림
	while(!q.empty())
	{
		Tom cur = q.front();
		q.pop();
		int curX = cur.x;
		int curY = cur.y;
		int curCount = cur.Count;
		count = curCount;
		
		for(int dir = 0; dir < 4; dir++)
		{
			int nextY = curY + dy[dir];
			int nextX = curX + dx[dir];
			int nextCount = curCount + 1;
			
			if(nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) continue;
			if(visited[nextY][nextX] == 0 && Tomato[nextY][nextX] == 0)
			{
				Tom Next;
				Next.y = nextY;
				Next.x = nextX;
				Next.Count = nextCount;
				
				visited[nextY][nextX] = 1;
				Tomato[nextY][nextX] = 1;
				q.push(Next);
			}
		}
	}
	 
	return count;
}

int main(void)
{
	cin >> M >> N;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cin >> Tomato[i][j];
		}
	}
	
	int result = bfs();
	bool flag = true;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(Tomato[i][j] == 0)
			{
				flag = false;
				break;
			}
		}
	}
	
	if(flag)
		cout << result << "\n";
	else
		cout << -1 << "\n";
	
	return 0;
}
