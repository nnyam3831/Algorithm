// 3차원 배열  

#include <iostream>

using namespace std;

int Dp[1001][3][31];
int array[1001];

int main(void)
{
	int T, W;
	int MaxResult; 
	cin >> T >> W;
	for(int i = 1; i <= T; i++)
	{
		cin >> array[i];
	}
	for(int i = 1; i <= T; i++)
	{
		for(int k = 0; k <= W; k++)
		{
			if(array[i] == 1)
			{
				Dp[i][1][k] = max(Dp[i][1][k], Dp[i-1][1][k] + 1);
				Dp[i][1][k] = max(Dp[i][1][k], Dp[i-1][2][k-1] + 1);
				
				Dp[i][2][k] = max(Dp[i][2][k], Dp[i-1][2][k]);
				Dp[i][2][k] = max(Dp[i][2][k], Dp[i-1][1][k-1]);
			}
			
			else
			{
				Dp[i][1][k] = max(Dp[i][1][k], Dp[i-1][1][k]);
				Dp[i][1][k] = max(Dp[i][1][k], Dp[i-1][2][k-1]);
				
				Dp[i][2][k] = max(Dp[i][2][k], Dp[i-1][2][k] + 1);
				Dp[i][2][k] = max(Dp[i][2][k], Dp[i-1][1][k-1] + 1);
			}
		}
	}
	
	for(int k = 0; k <= W; k++)
	{
		MaxResult = max(MaxResult, Dp[T][1][k]);
		MaxResult = max(MaxResult, Dp[T][2][k]);
	}
	
	cout << MaxResult << endl;
	
	return 0;
}
