#include <iostream>
#include <vector>
#define MAX 100+1
using namespace std;

int N, P, cnt;
int visited[MAX];
vector<int> v[MAX];

void DFS(int x)
{
	cnt++;
	visited[x] = 1;
	for(int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];
		if(visited[y] == 0)
		{
			visited[y] = 1; 
			DFS(y);
		}
	}
}
int main(void)
{
	cin >> N;
	cin >> P;
	for(int i = 0; i < P; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	DFS(1);
	
	cout << cnt-1 << endl;
	
	return 0;
}
