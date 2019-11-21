#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#define MAX 10001

using namespace std;

int id, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int>> SCC;
stack<int> s;

int dfs(int x)		// 처음 방문하는 노드만 실행(N번) 
{
	d[x] = ++id;
	s.push(x);
	
	int result = d[x];
	for(int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		if(d[y] == 0) result = min(result, dfs(y));
		if(!finished[y]) result = min(result, d[y]);
	}
	
	if(result == d[x])
	{
		vector<int> scc;
		while(1)
		{
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if(t == x) break;
		}
		
		sort(scc.begin(), scc.end());
		SCC.push_back(scc);
	}
	
	return result;
}

int main(void)
{
	int V, E;
	cin >> V >> E;
	for(int i = 1; i <= E; i++)
	{
		int index, k;
		cin >> index;
		cin >> k;
		a[index].push_back(k);
	}
	
	for(int i = 1; i <= V; i++)
	{
		if(d[i] == 0) dfs(i);
	}
	
	cout << SCC.size() << endl;
	sort(SCC.begin(), SCC.end());
	for(int i = 0; i < SCC.size(); i++)
	{
		for(int j = 0; j < SCC[i].size(); j++)
		{
			printf("%d ", SCC[i][j]);
		}
		printf("-1\n");
	}
	
	return 0;
}
