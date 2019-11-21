#include <iostream>

using namespace std;

int dp[501][501];			// iÃþ j¹øÂ°  
int main(void)
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			cin >> dp[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			if(j == 1)
				dp[i][j] += dp[i-1][j];
			else if(j == i)
				dp[i][j] += dp[i-1][j-1];
			else
			{
				dp[i][j] = max(dp[i][j] + dp[i-1][j-1], dp[i][j] + dp[i-1][j]);
			}
		}
	}
	int Max = dp[n][1];
	for(int i = 2; i <= n; i++)
	{
		Max = max(Max, dp[n][i]);
	}
	cout << Max << endl;
	return 0;
}
