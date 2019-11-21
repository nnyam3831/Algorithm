#include <iostream>

using namespace std;

int D[100001][3];		// 0 : 위 선택 / 1 : 아래선택 / 3 : None 
int Array[100001][2]; 
int main(void)
{
	int T, n;
	cin >> T;
	int *result = new int[T];
	for(int i = 1; i <= T; i++)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> Array[i][0];
		}
		for(int i = 1; i <= n; i++)
		{
			cin >> Array[i][1];
		}
		D[1][0] = Array[1][0];
		D[1][1] = Array[1][1];
		D[1][2] = 0;
		if(n == 1)
		{
			result[i] = max(D[1][0], D[1][1]);
			continue;
		}
		for(int i = 2; i <= n; i++)
		{
			D[i][0] = max(D[i-1][1] + Array[i][0], D[i-1][2] + Array[i][0]); // 이번에 위 선택 하면  
			D[i][1] = max(D[i-1][0] + Array[i][1], D[i-1][2] + Array[i][1]); // 이번에 아래 선택 하면 
			// 이번에 선택 안하면 저번에 최대값  
			int temp = D[i-1][0];
			for(int j = 1; j <= 2; j++)
			{
				temp = max(temp, D[i-1][j]);
			}
			D[i][2] = temp;
		}
		result[i] = D[n][0];
		result[i] = max(result[i], D[n][1]);
		result[i] = max(result[i], D[n][2]);
	}
	for(int i = 1; i <= T; i++)
	{
		cout << result[i] << endl;
	}
	delete result;
	
	return 0;
}
