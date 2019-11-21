#include <iostream>

using namespace std;

int SquareNumber[100001];
int Dp[100001];
int WhatisNumber(int N)
{
	if(N == 1) return 1;
	if(SquareNumber[N]) return N;
	
	for(int i = 1; i <= N; i++)
	{
		if(i*i > N) return (i-1)*(i-1);
		else if(i*i==N) return N;
	}
}

int DFS(int N)
{
	if(WhatisNumber(N) == N) return 1;
	if(N == 0) return 1;
	if(Dp[N]) return Dp[N];
	if(N == 1) return 1;
	
	return Dp[N] = DFS(N-WhatisNumber(N)) + DFS(WhatisNumber(N));
}

int main(void)
{
	int N;
	cin >> N;
	
	Dp[1] = 1;
	Dp[0] = 1;
	
	cout << DFS(N) << endl;
	return 0;
}
