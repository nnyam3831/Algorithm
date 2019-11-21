#include <iostream>

using namespace std;

int Dp[12];
int result[20];
int oneTwoThree(int N)
{
	if(N == 1)
		return Dp[1] = 1;
	if(N == 2)
		return Dp[2] = 2;
	if(N == 3)
		return Dp[3] = 4;
		
	return Dp[N] = oneTwoThree(N-3)+oneTwoThree(N-2) + oneTwoThree(N-1);
}
int main(void)
{
	int T, n;
	cin >> T;
	for(int i = 1; i <= T; i++)
	{
		cin >> n;
		result[i] = oneTwoThree(n);
	} 
	
	for(int i = 1; i <= T; i++)
	{
		cout << result[i] << endl;
	}
	return 0;
}
