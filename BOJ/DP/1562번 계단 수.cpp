#include <iostream>
#include <memory.h>

using namespace std;

const int MAX = 100 + 1;
const int MOD = 1000000000;

int N;
int D[10][MAX][1 << 10];

int DFS(int start, int Length, int Bit)
{
	
	// 기저부터
	if(Length == N) return Bit == (1<<10)-1 ? 1 : 0;
	
	int &result = D[start][Length][Bit];
	if(result != -1) return result;
	
	result = 0;
	if(start - 1 >= 0)
	{
		result += DFS(start-1, Length+1, Bit | 1 << (start-1));
	}
	if(start + 1 < 10)
		result += DFS(start+1, Length+1, Bit | 1 << (start+1)); 
		
	result %= MOD;
	return result;
}
int main(void)
{
	cin >> N;
	int result = 0;
	
	for(int i = 1; i <= 9; i++)
	{
		memset(D, -1, sizeof(D));
		result += DFS(i, 1, 1 << i);
		result %= MOD;
	}

	cout << result << endl;
	return 0;
}
