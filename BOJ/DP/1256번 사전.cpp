#include <iostream>

using namespace std;

int N, M, K, D[201][201];

int main(void)
{
	for(int i = 0; i <= 200; i++)
	{
		D[i][0] = 1;
		for(int j = 1; j <= i; j++)
		{
			D[i][j] = min(D[i-1][j-1]+D[i-1][j], (int)1e9);
		}
	}
	cin >> N >> M >> K;
	
	int tot = N + M;
	if(K > D[tot][N]) puts("-1");
	else
	{
		for(int i = 0; i < tot; i++){
			if(K > D[N+M-1][M])				// 전체 N+M-1개 a개 N-1개 
			{
				
				printf("z");
				K -= D[N+M-1][M];
				M--;
			}
			else
			{
				
				printf("a");
				N--;
			}
	
		}
	}
	return 0;
}
