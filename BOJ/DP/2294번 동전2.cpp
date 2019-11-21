#include <iostream>
#include <algorithm>
using namespace std;

int Coin2(int N);
int Dp[10001];
int input[101];
int main(void)
{
	int n, k;
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> input[i];
	}
	sort(input+1, input + (n+1));
	Dp[0] = 0;
	for(int i = 1; i <= k; i++)
	{
		bool flag = false;
		int Min = 1000000000;
		for(int j = 1; j <= n; j++)
		{
			if(i < input[j]) break;
			if(Dp[i-input[j]] != -1)
			{
				Min = min(Min, Dp[i-input[j]]);	// 여기를Min 하고 같이 묶어서 잘 안풀렷음  
				flag = true;
			}
			else{
				continue;
			}
			
		}
		if(flag)
			Dp[i] = Min + 1;
		else
			Dp[i] = -1;
	}
	
	cout << Dp[k] << endl;
	return 0;
}


