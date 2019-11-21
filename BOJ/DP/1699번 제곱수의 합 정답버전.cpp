#include <stdio.h>

int main(void)
{
	int N;
	int Dp[100001] = {};
	
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j *j <= i; j++)
		{
			if(Dp[i] > Dp[i-j*j] + 1 || Dp[i] == 0)
				Dp[i] = Dp[i-j*j] + 1;
		}
	}
	
	printf("%d\n", Dp[N]);
	
	return 0;
}

