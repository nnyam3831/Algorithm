#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 25 + 1

using namespace std;

int N;
char Map[MAX][MAX];
int visited[MAX][MAX];
vector<int> v;
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int bfs(int y, int x)
{
	int ret = -1;
	if(visited[y][x] == 1) return ret;
	if(Map[y][x] == '0') return ret;
	
	visited[y][x] = 1;
	ret = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	
	while(!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;
	
		q.pop();
		
		for(int dir = 0; dir < 4; dir++)
		{
			int nextY = curY + dy[dir];
			int nextX = curX + dx[dir];
			if(nextY < 0 || nextY >= N || nextX < 0 || nextX >= N) continue;
			if(visited[nextY][nextX] == 0 && Map[nextY][nextX] == '1')
			{
				visited[nextY][nextX] = 1;
				q.push(make_pair(nextY, nextX));
				ret++;
			}
		}
	}
	
	return ret;
}

int main(void)
{
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		cin >> Map[i];
	}
	
	
	int result = -1;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			result = bfs(i, j);
			if(result != -1)
			{
				v.push_back(result);
			}
		}
	}
	
	sort(v.begin(), v.end());
	
	cout << v.size() << "\n";
	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\n";
	}
	return 0;
} 
