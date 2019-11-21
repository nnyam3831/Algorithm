// lower bound

#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int LIS[40001];
int Array[40001];

int N, Ans = 0, Size = 1;

int main(void)
{
	cin >> N;
	
	for(int i = 1; i <= N; i++)
		cin >> Array[i];
		
	LIS[1] = Array[1];
	
	int temp;
	for(int i = 2; i <= N; i++)
	{
		if(LIS[Size] < Array[i])
		{
			Size++;
			LIS[Size] = Array[i];
			continue;
		}
		temp = lower_bound(LIS+1, LIS+Size+1, Array[i]) - LIS;
		LIS[temp] = Array[i];
	}
	Ans = Size;
	cout << Ans << endl;

	return 0;
}
