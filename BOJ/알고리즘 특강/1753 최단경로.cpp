// 최단경로... 다익스트라 알고리즘
// O(V^2+E) O(ElogE)
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 20000+1
#define INF 987654321
using namespace std;

typedef pair<int, int> pii;
vector<pii> graph[MAX];
int D[MAX];
int main(void) {
	
	int V, E, K;
	cin >> V >> E;
	cin >> K;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
	}
	for (int i = 0; i <= V; i++) D[i] = INF;
	D[K] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(make_pair(0, K));
	
	while (!pq.empty()) {
		int curIndex = pq.top().second;
		int curDist = pq.top().first;
		pq.pop();
		for (int j = 0; j < graph[curIndex].size(); j++) {
			int next = graph[curIndex][j].first;
			int dist = graph[curIndex][j].second;
			if (D[next] > curDist + dist) {
				D[next] = curDist + dist;
				pq.push(make_pair(curDist + dist, next));
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		D[i] == INF?  cout << "INF\n" : cout << D[i] << "\n";
	}
	return 0;
}
