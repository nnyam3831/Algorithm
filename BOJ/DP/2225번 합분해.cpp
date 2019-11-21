#include <iostream>

using namespace std;
long Dp[201][201];

int main(void)
{
	int N, K;
	cin >> N >> K;
	for(int i = 0; i <= N; i++)
		Dp[i][1] = 1;
	for(int i = 0; i <= N; i++)
	{
		for(int h = 2; h <= K; h++)
		{
			for(int j = 0; j <= i; j++)
			{
				Dp[i][h] += Dp[i-j][h-1]; 
				Dp[i][h] %= 1000000000;
			}
		}

	}
	

	
	cout << Dp[N][K] << endl;
	return 0;
}
