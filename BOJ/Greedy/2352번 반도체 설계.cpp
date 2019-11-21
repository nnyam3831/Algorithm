#include <iostream>
#include <algorithm>

using namespace std;

int linked[40001];

int main(void)
{
	int n;
	int Max = 0;
	int result;
	
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> linked[i];
	}
	
	for(int i = 1; i <= n; i++)
	{
		
		Max = 1;
		int temp = linked[i];
		for(int j = i ; j <= n; j++)
		{
			if(linked[j] > temp )
				{
					Max++;
					temp = linked[j];
				}
		}
		result = max(result, Max);
	}
	
	cout << result << endl;
	return 0;
}

