#include <stdio.h>

int main(void)
{
	int list[11];
	int count = 0;
	int N, K;
	scanf("%d %d", &N, &K);
	
	for(int i = 1; i <= N; i ++)
	{
		scanf("%d", &list[i]);				// list[1] ~ list[10]
	}
	for(int j = N; j >= 1; j--)
	{
	
		if(K >= list[j])
		{
			count += K / list[j];
			K = K % list[j];
		}
		if(K == 0) break;
	}
	printf("%d", count);
	return 0;
}
