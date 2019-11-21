#include <iostream>

using namespace std;

int Fixed[41];
int Dp[41][2];
int main(void)
{
	int N, M;
	Dp[1][0] = 1;
	
	cin >> N;
	cin >> M;
	for(int i = 1; i <= M; i++)
	{
		cin >> Fixed[i];
	}
	for(int i = 2; i <= N; i++)
	{
		Dp[i][0] = Dp[i-1][0] + Dp[i-1][1];
		Dp[i][1] = Dp[i-1][0];
	}
	int result = 1;
	if(M != 0)
	{
		
		int index = N+1;
		for(int i = M; i >= 1; i--)
		{
			int temp = (Dp[index-Fixed[i]-1][0] + Dp[index-Fixed[i]-1][1]);
			if(temp != 0) result *= temp;
			index = Fixed[i];
		}
		int temp = (Dp[index - 1][0] + Dp[index-1][1]);
		if(temp != 0) result *= temp;
		
		cout << result << endl;
	}
	else
	{
		cout << Dp[N][1] + Dp[N][0] << endl;
	}
	
	return 0;
}
