#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(const int A, const int B)
{
	return A > B;
}
int Tower[100001];
int main(void)
{
	int N;
	int sum = 0;
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		cin >> Tower[i];
		sum += Tower[i];
	}

	sort(Tower+1, Tower+1+N, cmp);
	int Number = N;
	int cnt = 0;
	int index = 1;
	while(sum != 0)
	{
		if(Tower[index] >= Number)
			{
				Number--;
				sum -= Tower[index];
				cnt++;

				index++;
			}
			else
			{

				for(int j = index; j <= N; j++)
				{
					if(Tower[j] == 0) continue;
					Tower[j]--;
					if(Tower[j] == 0) Number--;
					sum--;
				}
				cnt++;
			}
		
		
		}
	
	
	cout << cnt << endl;
	
	return 0;
}
