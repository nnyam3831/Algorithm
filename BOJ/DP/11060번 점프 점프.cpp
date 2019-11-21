#include <iostream>
#include <limits.h>
using namespace std;

int D[1001];
int A[1001];
int main(void)
{
	int N;
	int result = -1;
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}

	if(N == 1) cout << 0 << endl;
	else
	{
	for(int i = 2; i <= N; i++)
	{
		int Min = INT_MAX-1;
		for(int j = i-1; j >= 1; j--)
		{
			if(A[j] >= i-j) // jump °¡´É
			{
				Min = min(Min,D[j] + 1);
			} 
		}
		if((Min == INT_MAX-1))
		{
			D[N] = -1;
			break;
		}
		if(Min != INT_MAX-1) D[i] = Min;
	}

	
	cout << D[N] << endl;
}
	return 0;
}
