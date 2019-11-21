#include <stdio.h>
#include <cstring>
#define sm(a,b) a < b ? a : b

int coin[3] = {1, 10, 25};
int dp[101];
using namespace std;

int main(void)
{
	int TC, cnt;
	long long n;
	scanf("%d", &TC);
	
	memset(dp, 127, sizeof(dp));
	dp[0] = 0;
	for(int i = 1; i <= 100; i++)
	{
		for(auto &e1 : coin)
		{
			if(i-e1 > -1) dp[i] = sm(dp[i], dp[i-e1]+1);
		}
	}
	while(TC--)
	{
		scanf("%lld", &n);
		cnt = 0;
		while(n!=0)
		{
			cnt += dp[n%100];
			n /= 100;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
