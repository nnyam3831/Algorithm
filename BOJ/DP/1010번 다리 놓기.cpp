#include <iostream>

using namespace std;

int D[31][31];
int main(void)
{
	int T;
	cin >> T;
	D[1][1] = 1;
	D[1][1] = 1;
	int *result = new int[T];
	for(int i = 1; i <= T; i++)
	{
		int N, M;
		cin >> N >> M;
		for(int i = 1; i <= N; i++)
		{
			for(int j = i; j <= M; j++)
			{
				if(i == 1)
					D[i][j] = j;
				else if(i == j)
					D[i][j] = 1;
				else
					D[i][j] = D[i][j-1] + D[i-1][j-1];
			}
		}
		result[i] = D[N][M];
	}
	for(int i = 1; i <= T; i++)
	{
		cout << result[i] << endl;
	}
	delete result;
	return 0;
}
