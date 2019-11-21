#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int Abs(int A, int B)
{
	if(A >= B) return A-B;
	else
		return B-A;
}
int Rank[500001];
int main(void)
{
	int N;
	long long int result = 0;
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> Rank[i];
	}
	
	sort(Rank+1, Rank+(1+N));
	
	for(int i = 1; i <= N; i++)
	{
		result += Abs(Rank[i], i);
	}
	
	cout << result << endl;
	
	return 0;
}
