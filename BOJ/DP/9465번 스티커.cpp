#include <iostream>

using namespace std;

int D[100001][3];		// 0 : �� ���� / 1 : �Ʒ����� / 3 : None 
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
			D[i][0] = max(D[i-1][1] + Array[i][0], D[i-1][2] + Array[i][0]); // �̹��� �� ���� �ϸ�  
			D[i][1] = max(D[i-1][0] + Array[i][1], D[i-1][2] + Array[i][1]); // �̹��� �Ʒ� ���� �ϸ� 
			// �̹��� ���� ���ϸ� ������ �ִ밪  
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
