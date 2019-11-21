#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define MAX 10001

using namespace std;

int V, E, id;
vector<int> a[MAX];
vector<vector<int>> SCC;
int d[MAX];
stack<int> s;
bool finished[MAX];

int dfs(int x)
{
	d[x] = ++id;
	s.push(x);
	
	int parent = d[x];
	for(int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		if(d[y] == 0) parent = min(parent, dfs(y));
		if(!finished[y]) parent = min(parent, d[y]);
	}
	
	if(parent == d[x])	// 내가 부모구나 
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
	return parent;
}

int main(void)
{
	cin >> V >> E;
	for(int i = 1; i <= E; i++)
	{
		int x,y;
		cin >> x >> y;
		a[x].push_back(y);
	}
	
	for(int i = 1; i <= V; i++)
	{
		if(d[i] == 0) dfs(i);
	}
	sort(SCC.begin(), SCC.end());
	cout << SCC.size(); 
	
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
