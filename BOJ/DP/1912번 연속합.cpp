#include <iostream>
#include <algorithm>
using namespace std;

int Array[100001];
int D[100001];
int main(void)
{
	int n;
	int result = 0;
	int MinusCnt = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> Array[i];
	}
	D[1] = Array[1];
	result = Array[1];
	for(int i = 2; i <= n; i++)
	{
		if(Array[i] >= 0)
		{
			D[i] = D[i-1] + Array[i];
			result = max(result,D[i]);
		}
		else
		{
			MinusCnt++;
			if(D[i-1] < -Array[i])
			{
				result = max(result, D[i-1]);
				D[i] = 0;
			}
			else
			{
				D[i] = D[i-1] + Array[i];
				result = max(result,D[i]);
			}
		}	
	}
	if(MinusCnt == n-1 && Array[1] < 0)
	{
		result = Array[1];
		for(int i = 1; i <= n; i++)
		{
			result = max(result, Array[i]);
		}
	}
	cout << result << endl;
	return 0;
}
