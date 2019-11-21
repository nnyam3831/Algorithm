#include <iostream>

using namespace std;

int Dp[301][301]; 		// N X M 2차원 배열 
int result[10001];
 
int main(void)
{
	int N, M, K;
	int i, j, x, y;
	int Array[301][301];
	
	cin >> N >> M;
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			cin >> Array[i][j]; 
		}
	}
	Dp[1][1] = Array[1][1];
	// (1,1) 부터 (i, j)까지의 합 
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			Dp[i][j] = Dp[i-1][j] + Dp[i][j-1] - Dp[i-1][j-1] + Array[i][j];
		}
	}

	cin >> K;
	for(int t = 1; t <= K; t++)
	{
		cin >> i >> j >> x >> y;
		result[t] = Dp[x][y] - Dp[i-1][y] - Dp[x][j-1] + Dp[i-1][j-1]; 
	}
	
	for(int i = 1; i <= K; i++)
	{
		cout << result[i] << endl;
	}
	return 0;
}
