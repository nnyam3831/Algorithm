#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1001;
bool Book[MAX];
bool cmp(pair<int,int> a, pair<int,int> b)
{
	if(!(a.second == b.second))
		return a.second < b.second;
	else
		return a.first < b.first;
}
int main(void)
{
	int T, N, M;
	cin >> T;
	for(int i = 1; i <= T; i++)
	{
		memset(Book, false, sizeof(Book));
		cin >> N >> M;
		
		vector <pair<int, int>> v;
		for(int j = 0; j < M; j++)
		{
			int a, b;
			cin >> a >> b;
			v.push_back({a, b});
		}
		sort(v.begin(), v.end(), cmp);
		int result = 0;
		for(int j = 0; j < M; j++)
		{
			for(int k = v[j].first; k <= v[j].second; k++)
			{
				if(!Book[k]){
					Book[k] = true;
					result++;
					break;
				}
			}
		}
		cout << result << endl;
	}
	
	
	return 0;
}
