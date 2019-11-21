#include <iostream>

using namespace std;

int Dp[101];
bool Yaksu(int N)
{
	int cnt = 0;
	for(int i = 1; i <= N; i++)
	{
		if(N % i == 0) cnt++;
	}
	if(cnt%2 == 1) return true;
	else return false;
}
int main(void)
{
	int T;
	cin >> T;
	int *result = new int[T];
	Dp[1] = 1;
	for(int i = 1; i <= T; i++)
	{
		int N;
		cin >> N;
		for(int j = 2; j <= N; j++)
		{
			if(Yaksu(j)) Dp[j] = Dp[j-1] + 1;
			else
				Dp[j] = Dp[j-1];
			
		}
		result[i] = Dp[N]; 
	}
	
	for(int i = 1; i <= T; i++)
	{
		cout << result[i] << endl;
	}
	
	delete result;
	return 0;
}
