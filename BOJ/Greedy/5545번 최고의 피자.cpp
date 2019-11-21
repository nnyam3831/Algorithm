#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(const int A, const int B)
{
	return A > B;
}
int Topping[200];
int main(void)
{
	int N, A, B, C;
	cin >> N;
	
	cin >> A >> B;
	cin >> C;
	for(int i = 1; i <= N; i++)
		cin >> Topping[i];
		
	sort(Topping+1,Topping+(N+1),cmp);
	
	int Max = C/A;
	
	// 토핑 1개부터 N개까지 비교  
	for(int i = 1; i <= N; i++)
	{
		int temp = 0;
		for(int j = 1; j <= i; j++)
		{
			temp += Topping[j];
		}
		Max = max(Max, (C+temp)/(A+i*B));
	}
	
	cout << Max << endl;
	return 0;
}
