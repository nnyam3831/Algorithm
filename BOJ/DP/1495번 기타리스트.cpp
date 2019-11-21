#include <iostream>

using namespace std;

int DP[101][1001];
int V[101];
int M;
int S;
int N;


int main(void)
{
	cin >> N >> S >> M;
	for(int i = 1; i <= N; i++)
	{
		cin >> V[i];
	}	
	
	DP[0][S] = 1;
	for(int i = 1; i <= N; i++)
	{
		for(int j = 0; j <= M; j++)
		{
			if(DP[i-1][j] == 0) continue;
			else
			 
			{
		
				if(V[i] + j <= M) DP[i][V[i]+j] = 1;
				if(j-V[i] >= 0) DP[i][j-V[i]] = 1;
			}
		}
	}
	for(int i = M; i >= 0; i--)
	{
		if(DP[N][i] == 1)
		{
			cout << i << endl;
			break;
		}
	
		if(i==0) cout << -1 << endl;
	}
	
	return 0;
}
