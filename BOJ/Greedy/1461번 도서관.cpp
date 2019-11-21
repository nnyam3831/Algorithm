#include <iostream>
#include <algorithm>
using namespace std;

int Book[10001];

int main(void)
{
	int N, M;
	cin >> N >> M;
	int index = -1;
	int result = 0;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> Book[i];
		
	}
	sort(Book+1, Book+(N+1));
	
	for(int i = 1; i <= N; i++)
	{
		if(i!=1)
		{
			if(Book[i-1] * Book[i] < 0) index = i;
		}
	}

	if(index != -1)
	{
		for(int i = 0; i <= (index-2)/M; i++)
		{
			int j = 1 + M*i;
			if(j == 1&&(Book[1]+Book[N]) < 0) result -= Book[j];
			else
				result -= 2*Book[j];
				
	
	
		}
		for(int i = 0; i <= (N-index)/M; i++)
		{
			int j = N - M*i;
			if(j==N&& (Book[1] + Book[N] >= 0)) result += Book[j];
			else
				result += 2*Book[j];
	
	
		
		}
		
	}
	else
	{
		for(int i = 0; i <= (N-1)/M; i++)
		{
			if(Book[1] < 0)
			{
				int j = 1 + M*i;
				if(j==1) result -= Book[j];
				else
					result -= 2*Book[j];
			}
			else
			{
				int j = N - M*i;
				if(j==N ) result += Book[j];
				else
					result += 2*Book[j];
			}

		}
	}
	
	cout << result << endl;
	return 0;
}

