#include <iostream>
#include <algorithm>
using namespace std;
int arr[100000];

int main(void)
{
	int N, result = 0;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	
	sort(arr, arr+N);
	for(int i = 0; i < N; i++)
	{
		if((N-i) * arr[i] >= result)
			result = (N-i) * arr[i];
	}
	cout << result << endl;
	return 0;
} 
