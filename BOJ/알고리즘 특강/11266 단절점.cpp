// 단절점.. 기본적으로 스패닝트리를 기준으로 생각해보면...
// 방문할때마다 id가 정해지고 DFS 한 번 탐색하면 다 정해짐
// ROOT 노드의 CHILD가 2개 이상이면 무조건 단절점 (DFS 트리에서)

#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10000 + 1

using namespace std;

int V, E, cnt;
vector<int> node[MAX];
bool isCutting[MAX];
int discover[MAX];

int DFS(int index, bool isRoot) {

	int child = 0;
	discover[index] = ++cnt;
	// 내 발견값이랑 내 child들의 발견값들의 최소값이랑 비교해서 return
	int ret = discover[index];
	for (int j = 0; j < node[index].size(); j++) {
		int next = node[index][j];
		if (discover[next]) {
			ret = min(ret, discover[next]);
			continue;
		}
		child++;
		int prev = DFS(next, false);
		// 뭔가 값 리턴함
		if (!isRoot && prev >= discover[index]) {
			// 이러면 단절점임
			isCutting[index] = true;
		
		}
		ret = min(ret, prev);
	}
	if (isRoot && child >= 2) {
		isCutting[index] = true;

	}
	return ret;
}
int main(void) {

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	for (int i = 1; i <= V; i++) {
		if (!discover[i]) DFS(i, true);
	}
	vector<int> result;
	int ans = 0;
	for (int i = 1; i <= V; i++) {
		if (isCutting[i]) {
			ans++;
			result.push_back(i);
		}
	}
	cout << ans << "\n";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << "\n";
	return 0;
}
