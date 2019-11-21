// 시간 초과 때문에 우선순위 큐를 써야함  
// 우선순위 큐는 기본적으로 MAX HEAP	 
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 300000;

int N, K;
int bag[MAX];
pair<int, int> jewelry[MAX];
priority_queue<int> pq;

int main(void)
{
	cin >> N >> K;
	
	for(int i = 0; i < N; i++)
	{
		cin >> jewelry[i].first >> jewelry[i].second;
	}
	for(int i = 0; i < K; i++)
	{
		cin >> bag[i];
	}
	// 무게기준 오름차순 정렬  
	sort(jewelry, jewelry + N);
	sort(bag, bag+K);
	
	long long result = 0;
	int idx = 0;
	for(int i = 0; i < K; i++)
	{
		while(idx < N && jewelry[idx].first <= bag[i])
			pq.push(jewelry[idx++].second);

		if(!pq.empty())
		{
			result += pq.top();
			pq.pop();
		}
		
	}
	cout << result << endl;
	return 0;
}

