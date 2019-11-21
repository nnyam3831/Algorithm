// Strongly Connected Component 

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 10000 + 1

using namespace std;

int id, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int>> SCC;
stack<int> s;

vector<int> City[101];
int Cost[101];

int dfs(int x){
	d[x] = ++id;
	s.push(x);
	int parent = d[x];
	for(int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		if(d[y] == 0) parent = min(parent,dfs(y));
		else if(!finished[y]) parent = min(parent, d[y]);
	}
	
	if(parent == d[x]){
		vector<int> scc;
		while(1)
		{
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if(t == x) break;
		}
		SCC.push_back(scc);
	}
	
	return parent;
}

int main(void)
{
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		cin >> Cost[i];
	}
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			char c;
			cin >> c;
			if(c == '1') a[i].push_back(j);
		}
	}
	
	for(int i = 1; i <= N; i++)
	{
		if(d[i] == 0) dfs(i);
	}
	
	int sum = 0;
	
	for(int i = 0; i < SCC.size(); i++)
	{
		int Min = 10000000;
		for(int j = 0; j < SCC[i].size(); j++)
		{
			Min = min(Min, Cost[SCC[i][j]]);
		}
		sum += Min;
		
	}
	
	cout << sum << endl;
	return 0;
} 
