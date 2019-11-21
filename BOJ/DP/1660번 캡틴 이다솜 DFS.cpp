#include <iostream>
#define INT_MAX 987654321

using namespace std;

int sum[200];					// N개로 만드는데 필요한 개수  
int Dp[300001];			// 최소 개수 

int DFS(int Ball, int Idx, int Count)
{
	if(Ball < 0) return INT_MAX;
	if(Dp[Ball]) return Dp[Ball];
	if(Idx < 1) return INT_MAX;
	if(Ball == 0) return Count;
	
	Dp[Ball] = min(DFS(Ball-sum[Idx], Idx, Count) + 1, DFS(Ball, Idx-1, Count));
	return Dp[Ball];
}

int main(void)
{
	int n;
	cin >> n;
	int index = 0;
	while(++index)
	{
		sum[index] = index*(index+1)*(index+2)/6;
		if(sum[index] >= 300000) break;
	}
	int MaxIndex = index - 1;
	
	for(int i = 1; i <= n; i++)
	{
		DFS(i, MaxIndex, 0);
	}
	cout << Dp[n] << endl;
	
	return 0;
}
