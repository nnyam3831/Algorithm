// ������.. �⺻������ ���д�Ʈ���� �������� �����غ���...
// �湮�Ҷ����� id�� �������� DFS �� �� Ž���ϸ� �� ������
// ROOT ����� CHILD�� 2�� �̻��̸� ������ ������ (DFS Ʈ������)

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
	// �� �߰߰��̶� �� child���� �߰߰����� �ּҰ��̶� ���ؼ� return
	int ret = discover[index];
	for (int j = 0; j < node[index].size(); j++) {
		int next = node[index][j];
		if (discover[next]) {
			ret = min(ret, discover[next]);
			continue;
		}
		child++;
		int prev = DFS(next, false);
		// ���� �� ������
		if (!isRoot && prev >= discover[index]) {
			// �̷��� ��������
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
