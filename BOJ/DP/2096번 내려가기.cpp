// 메모리절약 => 바로처리  

#include <iostream>

using namespace std;

int Table[3];
int MaxDp[2][3];
int MinDp[2][3];

int main(void)
{
	int N;
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
	
		scanf("%d %d %d", &Table[0], &Table[1], &Table[2]);
			
	
		MaxDp[1][0] = max(MaxDp[0][0], MaxDp[0][1]) + Table[0];
		MaxDp[1][1] = max(MaxDp[0][0], max(MaxDp[0][1], MaxDp[0][2])) + Table[1];
		MaxDp[1][2] = max(MaxDp[0][1], MaxDp[0][2]) + Table[2];
		
		MinDp[1][0] = min(MinDp[0][0], MaxDp[0][1]) + Table[0];
		MinDp[1][1] = min(MinDp[0][0], min(MinDp[0][1], MinDp[0][2])) + Table[1];
		MinDp[1][2] = min(MinDp[0][1], MinDp[0][2]) + Table[2];
	
		for(int j = 0; j < 3; j++)
		{
			MaxDp[0][j] = MaxDp[1][j];
			MinDp[0][j] = MinDp[1][j];
		}
	}
	cout << max(MaxDp[1][0], max(MaxDp[1][1], MaxDp[1][2])) << " ";
	cout << min(MinDp[1][0], min(MinDp[1][1], MinDp[1][2]));
	return 0;
} 
