#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 20000 + 1
#define INF 987654321
using namespace std;

int V, E, K;
typedef pair<int,int> pii;
vector<pii> graph[MAX];
int D[MAX];
int main(void){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V >> E;
	cin >> K;
	for(int i = 0; i < E; i++){
		int a, b, c;
		cin >> a >> b >> c;	
		graph[a].push_back(make_pair(b, c));
	}
	
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for(int i = 1; i <= V; i++){
		if(i == K) D[i] = 0;
		else D[i] = INF;
	}
	
	pq.push(pii(0,K));
	while(!pq.empty()){
		int curIndex = pq.top().second;
		int curDist = pq.top().first;
		pq.pop();
		for(int i = 0; i < graph[curIndex].size(); i++){
			int next = graph[curIndex][i].first;
			int dist = graph[curIndex][i].second;
			if(D[next] > curDist + dist){
				D[next] = curDist + dist;
				pq.push(pii(D[next],next));
			}
		}
	}
	for(int i = 1; i <= V; i++){
		if(D[i] == INF) cout << "INF\n";
		else cout << D[i] << "\n";
	}
	return 0;
}


