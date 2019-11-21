#include <iostream>

using namespace std;

int D[301][301];
int main(void)
{
	int N, M;
	cin >> N >> M;
	D[1][1] = 0;
	for(int i = 2; i <= M; i++)
	{
		D[1][i] = i-1;
	}
	for(int i = 2; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			D[i][j] = D[i-1][j] + D[1][j] + 1;
		}
	}
	cout << D[N][M] << endl;
	return 0;
}
