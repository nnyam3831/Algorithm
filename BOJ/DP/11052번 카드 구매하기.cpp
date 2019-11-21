#include <iostream>

using namespace std;

int D[1001];		// 최대 금액  
int P[1001];
int main(void)
{
	int N;
	int result = 0;
	
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		cin >> P[i];
	}
	D[0] = 0;
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			D[i] = D[i-j] + P[j];
			result = max(result, D[i]);
		}
		D[i] = result;
	
	}
	cout << result << endl;
	return 0;
} 
