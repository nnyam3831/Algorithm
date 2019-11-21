#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 100 + 1;
int N;
int A[MAX], B[MAX];			// A는 큰 쪽부터 B는 작은 쪽부터 찾아감
int vA[MAX], vB[MAX]; 
 
int main(void)
{
	ios_base::sync_with_stdio(0);

    cin.tie(0);
	cin >> N;
	vector<int> v;
	for(int i = 0; i < N; i++)
	{
		int a, b; 
		cin >> a >> b;
		A[a]++;
		B[b]++;
		
		for(int j = 1; j < MAX; j++)
		{
			vA[j] = A[j];
			vB[j] = B[j];
		}
		
		int result = 0;
		int indexA = 100;
		int indexB = 1;
		while(1)
		{
			while(indexA > 0 && vA[indexA] == 0)
				indexA--;
			while(indexB <= 100 && vB[indexB] == 0)
				indexB++;
				
			if(indexA == 0 || indexB == MAX)
				break;
				
			result = max(result, indexA+indexB);
			
			if(vA[indexA] > vB[indexB])
			{
				vA[indexA] -= vB[indexB];
				vB[indexB] = 0;
			}
			else
			{
				vB[indexB] -= vA[indexA];
				vA[indexA] = 0;
			}
			
		}
		v.push_back(result);
	}
	
	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\n";
	}
	return 0;
}
