#include <iostream>

using namespace std;

int Dp[1000001];
int main(void)
{
	int N;
	cin >> N;
	
	Dp[1] = 1;
	Dp[2] = 2;
	for(int i = 3; i <= N; i++)
	{
		Dp[i] = Dp[i-1] + Dp[i-2];
		Dp[i] %= 15746;
	}
	
	cout << Dp[N] << endl;
	return 0;
}
