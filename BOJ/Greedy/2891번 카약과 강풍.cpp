#include <iostream>

using namespace std;

int A[11];		// 망가졌는지 확인
int B[11];		// 여분 있는지 확인
 
int main(void)
{
	int N, S, R;
	cin >> N >> S >> R;
	for(int i = 1; i <= S; i++)
	{
		int x;
		cin >> x;
		A[x] = 1;
	}
	for(int i = 1; i <= R; i++)
	{
		int y;
		cin >> y;
		B[y] = 1;
	}
	

	for(int i = 1; i <= N; i++)
	{
		if(A[i] == 1)
		{
			if(B[i] == 1) A[i] = 0;
		}
		else
		{
			if((A[i-1] == 1) && i != 1)
			{
				if(B[i] == 1) {
					A[i-1] = 0;
					B[i] = 0;
				}
			}
			if((A[i+1] == 1) && i != N)
			{
				if(B[i] == 1) {
					A[i+1] = 0;
					B[i] = 0;
				}
			}
		}
	}
	int sum = 0;
	for(int i = 1; i <= N; i++)
	{
		if(A[i] == 1) sum++;
	}
	
	cout << sum << endl;
	return 0;
}
