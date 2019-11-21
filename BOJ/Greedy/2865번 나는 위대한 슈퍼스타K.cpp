#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(const double A, const double B)
{
	return A > B;
}
double Array[101];
int main(void)
{
	int N, M, K;
	cin >> N >> M >> K;
	
	for(int i = 1; i <= M; i++)
	{
		if(i == 1)
		{
			for(int j = 1; j <= N; j++)
			{
				int index;
				double point;
				cin >> index;
				cin >> point;
				Array[index] = point;
			}
		}
		else
		{
		for(int j = 1; j <= N; j++)
		{
			int index;
			double point;
			cin >> index;
			cin >> point;
			if(point > Array[index]) Array[index] = point;
		}
	}
	}
	
	sort(Array+1, Array+(N+1), cmp);
	
	float result = 0;
	for(int i = 1; i <= K; i++)
	{
		result += Array[i];
	}
	
	printf("%.1lf\n", result);
	return 0;
}
