#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const int MAX = 50;
const int INF = 987654321;

int N, M;
int arr[MAX][MAX];
int result[MAX][MAX];

void XOR(int y, int x)
{
	for(int i = y; i < y+3; i++)
	{
		for(int j = x; j < x+3; j++)
		{
			int temp = arr[i][j];
			arr[i][j] = 1 - temp;
		}
	}
}

int main(void)
{
	
	cin >> N >> M; 
	int cnt = 0;
	
	bool possible = false;
	for(int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		
		for(int j = 0; j < temp.length(); j++)
		{
			if(temp[j] == '0')
				arr[i][j] = 0;
			else
				arr[i][j] = 1;
		}
	}
	
	for(int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		
		for(int j = 0; j < temp.length(); j++)
		{
			if(temp[j] == '0')
				result[i][j] = 0;
			else
				result[i][j] = 1;
		}
	}

	if(N >= 3 && M >= 3)
	{
		for(int i = 0; i <=N-3; i++)
		{
			for(int j = 0; j <=M-3; j++)
			{
				if(arr[i][j] != result[i][j])
				{
					XOR(i, j);
					cnt++;
				}
				
				bool same = true; 
				for(int y = 0; y < N; y++)
				{
					for(int x = 0; x < M; x++)
					{
						if(arr[y][x] != result[y][x])
						{
							same = false;
							break;
						}
					}
				}
				if (same == true)
				{
					possible = true;
					break;
				}
			}
			if(possible)
				break;
		}
	}	
	else
	{
		possible = true;
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < M; j++)
			{
				if(arr[i][j] != result[i][j])
					possible = false;
			}
		}
	}
	
	if(possible)
		cout << cnt << endl;
	else
		cout << -1 << endl;
	return 0;
}
