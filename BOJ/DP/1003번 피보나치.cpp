#include <iostream>

using namespace std;

int D[41];
int zeroCount[41];
int oneCount[41];
int result[100][2];
int zero(int n);
int one(int n);
int fibonacci(int n)
{
	
	if(n == 0)
	{
		zeroCount[0] = 1;
		return D[n]= 0;
	}
	if(n == 1)
	{
		oneCount[1] = 1;
		return D[n]= 1;
	}
	else
	{
		if(D[n]) return D[n];
		zeroCount[n] = zero(n-1) + zero(n-2);
		oneCount[n] = one(n-1) + one(n-2);
		return D[n] = fibonacci(n-1) + fibonacci(n-2);
	}
}
int main(void)
{
	int T, N;
	cin >> T;
	for(int i = 1; i <= T; i++)
	{
		cin >> N;
		
		fibonacci(N);
		result[i][0] = zeroCount[N];
		result[i][1] = oneCount[N];
	}
	
	for(int i = 1; i<=T; i++)
	{
		cout << result[i][0] << " " << result[i][1] << endl;
	}
	return 0;
}
int zero(int n)
{
	if(n == 0)
		return zeroCount[n] = 1;
	if(n == 1)
		return zeroCount[n] = 0;
	else
		{
			if(zeroCount[n]) return zeroCount[n];
			return zeroCount[n] = zero(n-1) + zero(n-2);
		}
}
int one(int n)
{
	if(n == 0)
		return oneCount[n] = 0;
	if(n == 1)
		return oneCount[n] = 1;
	else
		{
			if(oneCount[n]) return oneCount[n];
			return oneCount[n] = one(n-1) + one(n-2);
		}
}
