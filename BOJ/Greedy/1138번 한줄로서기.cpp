#include <iostream>
#include <algorithm>

using namespace std;

int list[11];
int input[11];
int main(void)
{
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		cin >> input[i];
	}
	for(int i = 1; i <= N; i++)
	{
		int temp = 0;
		for(int j = 1; j <= N; j++)
		{
			if(temp) break;
			if(list[j] != 0)
				continue;
			else
			{	
				
				if(input[i] == 0)
					{
						list[j] = i;
						temp = 1;
					}
				else
					input[i]--;
					
				
			}
		}
	}
	
	for(int i = 1; i <= N; i++)
	{
		cout << list[i] << " ";
	}
	return 0;
}
