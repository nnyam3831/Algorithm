#include <iostream>

using namespace std;

long long int D[101][10];
int result[101];

long long int DFS(int i, int N)		// i로 끝나는 N자리 계단수 개수 
{
	
	if(i == 0)
	{
		if(N == 1) return 0;
		if(D[N][i]) return D[N][i];
		return D[N][i] = DFS(i+1, N-1);
	}
	else if(i == 9)
	{
		if(N == 1) return 1;
		if(D[N][i]) return D[N][i];
		return D[N][i] = (DFS(i-1, N-1) % 1000000000);
	}
	else
	{
		if(N == 1) return 1;
		if(D[N][i]) return D[N][i];
		return D[N][i] = (DFS(i-1,N-1) % 1000000000) + (DFS(i+1,N-1) % 1000000000);
		
	}
} 
int main(void)
{
	int N;
	cin >> N;
	
	long long int result = 0;
	for(int i = 0; i <= 9; i++)
	{
		result = result + (DFS(i, N) % 1000000000);
	
		
	}
	result %= 1000000000;
	cout << result << endl;
	return 0;
}

