#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int Count[5];
char DNA[1001][51];
char result[51];
int MaxCount;
char CalDNA(int Count[5])
{
	int temp[5];
	for(int i = 1; i<=4; i++)
	{
		temp[i] = Count[i];
	}
	sort(temp+1, temp+5);

	int Max = temp[4];
	MaxCount += temp[4];
	if(Max == Count[1])
		return 'A';
	else if(Max == Count[4])
		return 'C';
	else if(Max == Count[3])
		return 'G';
	else
		return 'T';
	
}

int main(void)
{
	int N, M;
	
	cin >> N >> M;
	for(int i = 1; i<= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			cin >> DNA[i][j];
		}
	}
	for(int j = 1; j <= M; j++)
	{
		for(int k = 1; k <= 4; k++)
			Count[k] = 0;
		for(int i = 1; i <= N; i++)
		{
			if(DNA[i][j] == 'A')
				Count[1]++;
			else if(DNA[i][j] == 'T')
				Count[2]++;
			else if(DNA[i][j] == 'G')
				Count[3]++;
			else
				Count[4]++;
		}
		result[j] = CalDNA(Count);
	}
	
	for(int i = 1; result[i] != NULL; i++)
	{
		cout << result[i];
	}
	printf("\n");
	MaxCount = N*M - MaxCount;
	cout << MaxCount << endl;
	return 0;
}
