#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int R_MAX = 10001;
const int C_MAX = 501;
bool visited[R_MAX][C_MAX];
char array[R_MAX][C_MAX];
int tempIndex[C_MAX];
int main(void)
{
	int R, C;
	int cnt = 0;
	memset(visited, false, sizeof(visited));
	
	cin >> R >> C;
	for(int i = 1; i <= R; i++)
	{
		for(int j = 1; j <= C; j++)
		{
			cin >> array[i][j];
		}
	}
	for(int i = 1; i <= R; i++)
	{
		int Index = i;
		bool success = true;
		memset(tempIndex, 0, sizeof(tempIndex));
		visited[i][1] = true;
		for(int j = 1; j < C; j++)
		{
			
			if(array[Index-1][j+1] == '.' && !visited[Index-1][j+1] && Index > 1 && !visited[Index][j+1] && !visited[Index+1][j+1])
			{
				tempIndex[j] = Index-1;
				Index = Index-1;
				continue;
			}
			else if(array[Index][j+1] == '.' && !visited[Index][j+1] && !visited[Index+1][j+1])
			{
				tempIndex[j] = Index;
				continue;
			}
			else if(array[Index+1][j+1] == '.' && !visited[Index+1][j+1] && Index < R)
			{
				tempIndex[j] = Index+1;
				Index = Index+1;
				continue;
			}
			else
			{
				success = false;
				break;
			}
			
		}
		if(success){
			for(int j = 1; j < C; j++)
			{
				visited[tempIndex[j]][j+1] = true;
			}
			cnt++;
		}
	
	}
	cout << cnt << endl;
	return 0;
}
