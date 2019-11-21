#include <iostream>
// LIS : 최장 증가 수열
 
using namespace std;

int Box[1001];
int Dp[1001];
int main(void)
{
	int N;
	int max = 0;
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		cin >> Box[i];
	}
	
	for(int i = 1; i <= N; i++)
	{
		Dp[i] = 1;
		for(int j = 1; j <= i; j++)
		{
			if(Box[j] < Box[i] && Dp[i] < Dp[j] + 1)
			{
				Dp[i] = Dp[j] + 1;
			}
		}
		if(max < Dp[i]) max = Dp[i];
	} 
	
	cout << max << endl;
	return 0;
}
