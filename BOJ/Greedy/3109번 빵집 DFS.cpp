#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MAX = 10000;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[3] = {{-1, 1},{0,1},{1,1}};

int R, C;
string graph[MAX];
bool visited[MAX][500];

bool DFS(int y, int x)
{
	visited[y][x] = true;
	if(x == C-1)	// µµÂø
		return true;
	
	for(int i = 0; i < 3; i++)
	{
		int nextY = y + moveDir[i].y;
		int nextX = x + moveDir[i].x;
		
		if(0 <= nextY && nextY < R && 0<=nextX && nextX <C)
		{
			if(!visited[nextY][nextX] && graph[nextY][nextX] == '.')
			{
				bool flag = DFS(nextY, nextX);
				if(flag)
					return flag;
			}
		}
	} 
	return false;
}

int main(void)
{
	cin >> R >> C;
	for(int i = 0; i < R; i++)
	{
		cin >> graph[i];
	}
	int result = 0;
	for(int i = 0; i < R; i++)
	{
		result += DFS(i,0);
	}
	cout << result << endl;
	return 0;
}
