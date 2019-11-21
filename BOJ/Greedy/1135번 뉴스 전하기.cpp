#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

vector<pii> vc[52];

bool cmp(const pii &a, const pii &b)
{
	return a.first > b.first;
}

int dfs(int here)
{
	int ret = 0;
	
	// ���� ����� ���Ͽ��� ��ȭ�ϴµ� �ɸ��� �ð�
	for(int i = 0; i < vc[here].size(); i++)
	{
		int next = vc[here][i].second;
		vc[here][i].first = 1 + dfs(next);
	 } 
	 
	 // ���Ͽ��� ��ȭ�ϴµ� ���� ���� �ɸ��� ������ ����  
	 sort(vc[here].begin(), vc[here].end(), cmp);
	 
	 // ���ĵ� ������� ��ȭ�Ҷ� 
	 for(int i = 0;i < vc[here].size(); i++)
	 {
	 	vc[here][i].first += i;
	 	ret = max(ret, vc[here][i].first);
	 }
	 
	 return ret;
}
