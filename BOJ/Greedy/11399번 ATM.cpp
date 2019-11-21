#include <iostream>
#include <algorithm>
using namespace std;

int list[1000];
int main(void)
{
	int N;
	int sum = 0;
	cin >> N;
	for(int i = 0 ; i < N; i++)
	{
		cin >> list[i];
	} 
	
	sort(list, list+N);		// N명 오름차순 정리 
	for(int i = 0; i < N; i++)
	{
		int temp = 0;
		for(int j = 0; j <= i; j++)
		{
			temp += list[j];
		}
		sum += temp;
	} 
	cout << sum << endl;
	return 0;
}
