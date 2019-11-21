#include <iostream>
#include <memory.h>
using namespace std;

const int MaxIndex = 101;
const int MaxCost = 10000 + 1;

int D[MaxIndex][MaxCost];
int M;
int N;
int Memory[MaxIndex];
int Cost[MaxIndex];

int DFS(int index, int totalCost)		// cost 비용 대비 최대 메모리  
{
	if(index >= MAX)
		return 0;
		
	if(D[index][totalCost] != -1) return D[index][totalCost];
	
	D[index][totalCost] = DFS(index+1, totalCost);			// 비활 안했을 때
	
	if(Cost[index] <= totalCost)
		D[index][totalCost] = max(D[index][totalCost], Memory[index] + DFS(index+1, totalCost-Cost[index]));
	
	return D[index][totalCost]; 
	
	
}
int main(void)
{
	cin >> N >> M;
	for(int i = 1; i <= N; i++)
	{
		cin >> Memory[i];
	}
	for(int i = 1; i <= M; i++)
	{
		cin >> Cost[i];
	}
	memset(D, -1, sizeof(D));
	int total = 0;
	
	while(1)
	{
		if(DFS(1, total) >= M)
		{
			cout << total << endl;
			break;
		}
		total++;
	}
	return 0;
}
