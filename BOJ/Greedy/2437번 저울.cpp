#include <iostream>
#include <algorithm>
using namespace std;

int Weight[1001];

int main(void)
{
	int N;
	int result = 1;
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		cin >> Weight[i];
	}
	sort(Weight+1, Weight+1+N);
	
	if(Weight[1] != 1)
		cout << 1 << endl;
	else
	{
		for(int i = 2; i <= N; i++)
		{
			if(Weight[i] > result+1)
			{
				break;
			}
			else
			{
				result += Weight[i];
			}
		}
		cout << result + 1 << endl;
	}
	
	return 0;
}
