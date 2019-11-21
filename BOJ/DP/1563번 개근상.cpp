#include <iostream>

using namespace std;

// L이  
int D[1001][3][2];	// 0 : O로 끝남, 1 : A로 끝남 , 2 : L로 끝남 
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
		// O일때 + 지각 한번도 없는 case 
		D[i][0][0] = (D[i-1][0][0] + D[i-1][1][0]) % MOD; 
		
		// O일때 + 지각 한 번 있는 CASE 
		D[i][0][1] = (D[i-1][0][1] + D[i-1][1][1] + D[i-1][2][1]) % MOD;
		
		// A일때 + 지각 한번도 없는 case
		if(i==2) D[i][1][0] = 2;
		else
		D[i][1][0] = (D[i-1][0][0] + D[i-2][0][0]) % MOD;
		
		// A일때 + 지각 한번있는 case 
		D[i][1][1] = (D[i-1][0][1] + D[i-1][2][1] + D[i-2][0][1] + D[i-2][2][1]) % MOD;
		
		// L일 때는 지각이 한번도 없어야됨
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
