#include <iostream>
#include <algorithm>
using namespace std;
int Dp[1001][3];
int main(void)
{
	int N;
	cin >> N;
	int array[1001][3];
	for(int i = 1; i <= N; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cin >> array[i][j];
		}	
	}
	Dp[1][0] = array[1][0];
	Dp[1][1] = array[1][1];
	Dp[1][2] = array[1][2];
	
	for(int i = 2; i <= N; i++)
	{
		Dp[i][0] = min(Dp[i-1][1], Dp[i-1][2]) + array[i][0];
		Dp[i][1] = min(Dp[i-1][0], Dp[i-1][2]) + array[i][1];
		Dp[i][2] = min(Dp[i-1][0], Dp[i-1][1]) + array[i][2];
	}
	
	int Min = Dp[N][0];
	Min = min(Min, Dp[N][1]);
	Min = min(Min, Dp[N][2]);
	cout << Min << endl;
	return 0;
}
