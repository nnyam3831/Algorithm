#include <iostream>
#include <algorithm>

using namespace std;

int packagePrice[51];
int onePrice[51];

int main(void)
{
	int N, M, Min;
	cin >> N >> M;
	for(int i = 1; i <= M; i++)
	{
		cin >> packagePrice[i] >> onePrice[i];
	}
	sort(onePrice+1, onePrice+(M+1));
	sort(packagePrice+1, packagePrice+(M+1));
	

	if(6*onePrice[1] < packagePrice[1])
	{
		Min = N * onePrice[1];
	}
	
	else
	{
		if((N%6) * onePrice[1] < packagePrice[1])
		{
			Min = (N/6)*packagePrice[1] + (N%6) * onePrice[1];
		}
		else
		{
			Min = ((N/6) + 1) * packagePrice[1];
		}
		
	}
	
	cout << Min << endl;
	
	return 0;
}
