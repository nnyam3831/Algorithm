#include <iostream>

using namespace std;

// L��  
int D[1001][3][2];	// 0 : O�� ����, 1 : A�� ���� , 2 : L�� ���� 
int Count;
const int MOD = 1000000;
int main(void)
{
	int N;
	cin >> N;
			
	D[1][0][0] = 1;
	D[1][0][1] = 0;
		
	D[1][1][0] = 1;
	D[1][1][1] = 0;
	
	D[1][2][0] = 0;
	D[1][2][1] = 1;
	
	if(N >= 2)
	for(int i = 2; i <= N; i++)
	{
		// O�϶� + ���� �ѹ��� ���� case 
		D[i][0][0] = (D[i-1][0][0] + D[i-1][1][0]) % MOD; 
		
		// O�϶� + ���� �� �� �ִ� CASE 
		D[i][0][1] = (D[i-1][0][1] + D[i-1][1][1] + D[i-1][2][1]) % MOD;
		
		// A�϶� + ���� �ѹ��� ���� case
		if(i==2) D[i][1][0] = 2;
		else
		D[i][1][0] = (D[i-1][0][0] + D[i-2][0][0]) % MOD;
		
		// A�϶� + ���� �ѹ��ִ� case 
		D[i][1][1] = (D[i-1][0][1] + D[i-1][2][1] + D[i-2][0][1] + D[i-2][2][1]) % MOD;
		
		// L�� ���� ������ �ѹ��� ����ߵ�
		D[i][2][1] = (D[i-1][0][0] + D[i-1][1][0]) % MOD;  
	}
	
	int result = 0;
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 2; j++)
		{
	
			result += D[N][i][j];
			result %= MOD;
		}
	}
	
	cout << result << endl;
	
	return 0;
}
