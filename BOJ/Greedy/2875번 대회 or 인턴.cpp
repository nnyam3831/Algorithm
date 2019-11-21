#include <iostream>
using namespace std;

int main(void)
{
	int N, M, K;
	int rest = 0;
	int count = 0;
	int ans;
	cin >> N >> M >> K;
	if(N > 2*M)
	{
		ans = M;
		rest = N - 2*M;
	}
	else if(N == 2*M)
	{
		ans = M;
	}
	else if(N < 2*M)
	{
		ans = N / 2;
		rest = N+M - 3*(N/2);
	}

	while(1)
	{
		if(rest - K >= 0)
			break;
		else
			{
				K -= rest;
				if(K ==0 ) break;
			}
		ans = ans - (((K-1) / 3) + 1);
		break;
	}
	cout << ans << endl;
	return 0;
}
