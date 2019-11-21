#include <iostream>
#include <memory.h>
using namespace std;

int Dp[501][501];
int Arr[501][501];
int n;
int vectX[4] = {0, 1, 0, -1};
int vectY[4] = {1, 0, -1, 0};
int DFS(int x, int y)
{
	if(Dp[x][y]) return Dp[x][y];
	
	Dp[x][y] = 1;
	
	for(int i = 0; i < 4; i++)
	{
		int nextX = x + vectX[i];
		int nextY = y + vectY[i];
		
		if(nextX < 1 || nextX > n || nextY < 1 || nextY > n)
			continue;
		if(Arr[x][y] >= Arr[nextX][nextY])
			continue;
			
		Dp[x][y] = max(Dp[x][y], DFS(nextX,nextY)+1);
	}
	
	return Dp[x][y];
}
int main(void)
{
	int temp = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> Arr[i][j];
		}
	}

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{

			temp = max(temp, DFS(i,j));
		}
	}
	
	cout << temp << endl;
		
	return 0;
}
