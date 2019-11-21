#include <iostream>

using namespace std;

long long D[101][101][101];

int main(void)
{
	int N, R, L;
	
	cin >> N >> R >> L;
	
	D[1][1][1] = 1;
	for(int i = 2; i <= N; i++)
	{
		for(int j = 1; j <= L; j++)
		{
			for(int k = 1; k <= R; k++)
			{
				D[i][j][k] = D[i-1][j-1][k] + D[i-1][j][k-1] + D[i-1][j][k] * (i-2);
				D[i][j][k] %= 1000000007;
			}
		}
	}
	

	cout << D[N][L][R] % 1000000007 << endl;
	
	return 0;
}
