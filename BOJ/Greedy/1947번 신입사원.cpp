#include <iostream>
#include <algorithm>
using namespace std;

struct Score{
	int first, second;
};

bool cmp(const Score &A, const Score &B)
{
	return A.first < B.first;
}
int test[100001];

int main(void)
{
	int T, N;
	cin >> T;
	Score arr[100001];
	int result[21];
	
	for(int i = 1; i <= T; i++)
	{
		cin >> N;
		for(int j = 1; j <= N; j++)
		{
			cin >> arr[j].first >> arr[j].second;
		}
		// 정렬완료  
		sort(arr+1, arr+(N+1), cmp);
		
		int temp = arr[1].second;
		int count = 1;
		for(int j = 2; j <= N; j++)
		{
			if(temp > arr[j].second)
			{
				count++;
				temp = arr[j].second;
				
			}
		}
		result[i] = count;
		
	}
	for(int i = 1; i <= T; i++)
	{
		cout << result[i] << endl;
	}
	return 0;
}

















