#include <iostream>
#include <algorithm>

using namespace std;
int subject[1001];
int arr[1001];
int main(void)
{
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
	{
		int P, L;
		cin >> P >> L;
		for(int i = 0; i < P; i++)
		{
			cin >> subject[i];
		}
		if(P < L)
		{
			arr[i] = 1;
			continue;
		}
		else
		{
			sort(subject, subject+P);
			arr[i] = subject[P-L];
		}
	
	}
	int temp = 0;
	int cnt = 0;
	sort(arr+1, arr+1+n);
	for(int i = 1; i <= n; i++)
	{
		temp += arr[i];
		if(temp > m) break;
		cnt++;
	}
	
	cout << cnt << endl;
	
	return 0;
}
