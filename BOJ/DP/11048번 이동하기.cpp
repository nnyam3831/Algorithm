#include <iostream>
#include <memory.h>
#include <string.h>
using namespace std;

int Matrix[1001][1001];
int Dp[1001][1001];
int N, M;
int Solve(int i, int j)
{
	if(i == 1 && j == 1) return Matrix[1][1];
	if(Dp[i][j] != -1) return Dp[i][j];
	if(i < 1 || j < 1 || i > N || j > M) return 0;
	
	int Max = Solve(i-1, j);
	Max = max(Max, Solve(i,j-1));
	Max = max(Max, Solve(i-1,j-1));
	
	return Dp[i][j] = Max + Matrix[i][j]; 
}
int main(void)
{
	cin >> N >> M;

	memset(Dp, -1, sizeof(Dp));
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			cin >> Matrix[i][j];
		}
	}	
	
	cout << Solve(N, M) << endl;
	return 0;
}
