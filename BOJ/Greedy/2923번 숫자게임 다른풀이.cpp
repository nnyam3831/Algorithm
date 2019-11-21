#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100 + 1;

int A[MAX], B[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);

    cin.tie(0);
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		
		vector<int> vA(MAX), vB(MAX);
		A[a]++;
		B[b]++;
		for(int j = 0; j < MAX; j++)
		{
			vA[j] = A[j];
			vB[j] = B[j];
		}
		
		int result = 0;
		// aIdx�� ���� ū ��, bIdx�� ���� ���� ��
		int aIdx = 100, bIdx = 1;
		
		while(aIdx >= 1 && bIdx < MAX)
		{
			while(aIdx>=1 && vA[aIdx] == 0)
				aIdx--;
			while(bIdx<MAX && vB[bIdx] == 0)
				bIdx++;
				
			// ��� �� üũ
			if(aIdx == 0 || bIdx == MAX)
				break;
				
			result = max(result, aIdx+bIdx);
			
			if(vA[aIdx] > vB[bIdx])
			{
				vA[aIdx] -= vB[bIdx];
				vB[bIdx] = 0;
			}
			
			else
			{
				vB[bIdx] -= vA[aIdx];
				vA[aIdx] = 0;
			} 
		} 
	
		cout << result << "\n";
	}
	return 0;
}
