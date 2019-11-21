#include <iostream>
#include <limits.h>
#include <memory.h>
using namespace std;

int Mat[501][2];
int Dp[501][501];

int DFS(int start, int end)
{
	if(Dp[start][end] != -1) return Dp[start][end];
	if(start == end) return 0;
	
	int Min = INT_MAX;
	for(int i = start; i < end; i++)
	{
		Min = min(Min,  DFS(start, i) + DFS(i+1, end) + Mat[start][0]*Mat[i][1]*Mat[end][1]);
	}
	return Dp[start][end] = Min;
}
int main(void)
{
	int N;
	cin >> N;
	memset(Dp, -1, sizeof(Dp));
	for(int i = 1; i <= N; i++)
	{
		cin >> Mat[i][0] >> Mat[i][1];
	}
	
	cout << DFS(1,N) << endl;

	
	return 0;
}
