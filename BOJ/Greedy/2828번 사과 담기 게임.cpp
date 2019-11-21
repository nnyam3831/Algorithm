#include <iostream>

using namespace std;


int main(void)
{
	int N, M, j;
	int distance = 0;
	int index = 1;
	cin >> N >> M;
	cin >> j;
	
	
	for(int i = 1; i <= j; i++)
	{
		int t;
		cin >> t;
		
		// 포함인가 아닌가  
		if(t >= index && t <= index + M -1)
			continue;
		else
		{
			if(t >= index + M)
			{
				distance += t - index - (M - 1);
				index = t - (M-1);
			}
			else
			{
				distance += index - t;
				index = t;
			}
		} 
	}
	
	cout << distance << endl;
	return 0;
}
