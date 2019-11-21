#include <iostream>
#include <memory.h>
using namespace std;

char Matrix[1001][1001];
int D[1001][1001];


int N, M;
int DFS(int x, int y)
{
	if(D[x][y] != -1) return D[x][y];
	if(x < 1 || x > N || y < 1 || y > M || Matrix[x][y] == '0') 
		return D[x][y] = 0;
	
	// 일단 기본적으로 1이면 한개  
	D[x][y] = 1; 
	// 3개다 0이 아니면 하나씩 각각 탐색  
	int temp = 0;
	if(DFS(x+1,y) * DFS(x,y+1) * DFS(x+1,y+1))
	{
		temp = DFS(x+1, y);
		temp = min(temp, DFS(x,y+1));
		temp = min(temp, DFS(x+1,y+1));
	}
	D[x][y] += temp;
	return D[x][y];
	
}
int main(void)
{
	memset(D, -1, sizeof(D));
	cin >> N >> M;

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			cin >> Matrix[i][j];
		}
	}


	int ans = 0;
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			ans = max(ans, DFS(i,j));
		}
	}
	cout << ans*ans << endl;
	return 0;
}
