#include <iostream>

using namespace std;

int D[16];
int T[16];
int P[16];
int n;
int ans;

// dp
int dp(int day)
{
	if( day == n+1) return 0;
	if(day > n+1) return -100000000;
	if(D[day] > 0) return D[day];
	
	// 점화식 : 상담을 한다 안한다.  
	// 상담을 안한다면 다음날 상담, 한다면 정해진 일수 다음날 상담  
	return D[day] = max(dp(day+1), dp(day+T[day])+P[day]);
}

void dfs(int day, int sum)
{
	if(day == n+1)
	{
		ans = max(ans, sum);
		return;
	}x
	dfs(day+1, sum);
	if(day+T[day] <= n+1)
	{
		dfs(day+T[day], sum+P[day]);
	}
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> T[i] >> P[i];
	}
	cout << dp(1) << endl;
	
	return 0;
}
