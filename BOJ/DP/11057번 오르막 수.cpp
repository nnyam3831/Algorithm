#include <iostream>
#include <algorithm>

using namespace std;

long long int Dp[1001][10];		// 0~9
int main(void)
{
	int N;
	cin >> N;
	for(int i = 0; i <= 9; i++)
	{
		Dp[1][i] = 1;
	}
	for(int i = 2; i <= N; i++)
	{
		// i로 끝나는 길이 N의 오르막 수 = N-1자리 0~i-1  
		for(int j = 0; j <= 9; j++)
		{
			for(int k = 0; k <= j; k++)
			{
				Dp[i][j] += Dp[i-1][k];
			}
			Dp[i][j] %= 10007;
		}
	}
	long long int temp = 0;
	for(int i = 0; i <= 9; i++)
	{
		temp += Dp[N][i];
	}
	temp = temp % 10007;
	cout << temp << endl;
	return 0;
}
