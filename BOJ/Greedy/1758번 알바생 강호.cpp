// ���� ���� �����ؼ� ������ ���������� ������ �װ� ���� ū����  

#include <iostream>
#include <algorithm> 
using namespace std;

bool cmp(const int A, const int B)
{
	return A > B;
}

int Tip[100001];
int main(void)
{
	int N;
	int Key = 0;
	int index = 0;
	long long result = 0;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> Tip[i];
	}
	
	sort(Tip, Tip+N, cmp);
	
	
	for(int i = 0; i < N; i++)
	{
		if(Tip[i] - i <= 0)
		{
			break;
		}
		result += (Tip[i] - i);
	}
	
	
	
	cout << result << endl;
	return 0;
}
