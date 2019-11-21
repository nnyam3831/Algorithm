#include <iostream>

using namespace std;

int n, Dp[300001];

int main(void)
{
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		Dp[i] = 1e9;
		for(int j = 1, t; (t = j*(j+1)*(j+2)/6) <= i; j++)
		{
			Dp[i] = min(Dp[i], Dp[i-t] + 1);
		}
	}
	
	cout << Dp[n] << endl;
	return 0;
}
