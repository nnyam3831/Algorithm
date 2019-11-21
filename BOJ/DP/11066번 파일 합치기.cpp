#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

bool cmp(const int a, const int b)
{
	return a > b;
}
int Dp[1000];
int Array[1000];
int main(void)
{
	int T;
	cin >> T;
	
	int *result = new int(T);
	for(int j = 1; j <= T; j++)
	{
		int K;
		cin >> K;
		memset(Dp, 0, sizeof(Dp));
		memset(Array,0,sizeof(Array));
		for(int i = 1; i <= K; i++)
		{
			cin >> Array[i];
		}
	
		sort(Array+1, Array+(K+1));

		Dp[1] = 0;
		Dp[2] = Array[1] + Array[2];
	
		for(int i = 3; i <= K; i++)
		{
			if(i%2 == 1)	// È¦¼ö  
			{
				Dp[i] = 2* Dp[i-1] + Array[i];
			}
			else			// Â¦¼ö  
			{
				Dp[i] = min((Dp[i-1]+Dp[i-1]+Array[i]), 2*(Dp[i-2] + Array[i-1]+Array[i]));
			}
			printf("Dp[%d] : %d \n", i, Dp[i]);
		}
		
		result[j] = Dp[K];
	}
	for(int i = 1; i <= T; i++)
	{
		cout << result[i] << endl;
	}
	delete result;
	return 0;
}
